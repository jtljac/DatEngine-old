#pragma once
#include <iostream>
#include <typeinfo>
#include <unordered_map>
#include <set>
#include <DatVFS.h>
#include <Utilities/FileUtilities.h>
#include <Utilities/Logging.h>

#include "Assets/BaseAsset.h"
#include "./Factories/AssetFactory.h"

using TypeInfoRef = std::reference_wrapper<const std::type_info>;

struct TypeInfoHasher {
	std::size_t operator()(TypeInfoRef code) const
	{
		return code.get().hash_code();
	}
};

struct TypeInfoEqualTo {
	bool operator()(TypeInfoRef lhs, TypeInfoRef rhs) const
	{
		return lhs.get() == rhs.get();
	}
};

/**
 * A class that abstracts asset handling by storing all the assets used by the game in a single virtual files system, and
 * allowing access to assets via factories that automatically load the data from the disk and constructs it into the appropriate
 * asset type
 */
class AssetManager {
private:
	// Tag for logging
	inline const static std::string TAG = "Asset Manager";

	// Filetree containing assets
	DatVFS* fileTree = nullptr;

	// Factories for loading assets
	std::unordered_map<TypeInfoRef, AssetFactory*, TypeInfoHasher, TypeInfoEqualTo> factories;

	std::set<std::string> excludedExtensions;

	// TODO: Implement Cache

    /**
     * Populates the VFS with archive files and loose files
     * (Loose files are only loaded if enabled)
     * @see addArchives
     * @see addLooseFiles
     */
	void populate();

    /**
     * Adds the content of all the archive files in the resources directory to the VFS
     */
	void addArchives();
    /**
     * Adds all the loose files in the resources directory to the VFS
     */
	void addLooseFiles();


public:
	AssetManager();
	~AssetManager();

    /**
     * Excludes files with the given extension when loading loose files
     * @see addLooseFiles
     * @param extension The extension to exclude
     */
    [[maybe_unused]] void addExtensionExclusion(const std::string& extension) {
		excludedExtensions.insert(extension);
	}

    /**
     * Excludes files with the given extensions when loading loose files
     * @see addLooseFiles
     * @param extensions A list of extensions to exclude
     */
    [[maybe_unused]] void addExtensionExclusions(std::vector<std::string> &extensions) {
		for (const std::string& extension : extensions) {
			excludedExtensions.insert(extension);
		}
	}

    /**
     * Register an asset factory for instantiating assets from the VFS
     * @see AssetFactory
     * @tparam AssetType The asset type that this factory will create
     * @param Factory An instance of the asset factory
     */
	template<class AssetType>
	void registerFactory(AssetFactory* Factory) {
		factories[typeid(AssetType)] = Factory;
	}

    /**
     * Load an asset at the given path as an instance of the AssetType
     * @tparam AssetType The type of the asset being loaded (Note not the factory type)
     * @param thePath The path to the asset in the VFS
     * @return an instance of the asset
     */
	template<class AssetType>
    AssetType* loadAsset(const std::string& thePath) {
		std::vector<char> data = fileTree->getFile(thePath)->getContent();
		AssetFactory* factory;

		if (factories.count(typeid(AssetType)) == 0) {
            Log::warn(TAG, "Failed to load factory for type: " + std::string(typeid(AssetType).name()));
			return nullptr;
		}

		factory = factories.at(typeid(AssetType));

		BaseAsset* asset = factory->load(data);

		// Cast the asset to the requested format, as the factory should return the class as the base class
        auto* actualAsset = static_cast<AssetType*>(asset);

		Log::info(TAG, "Loaded asset " + thePath);

		return actualAsset;
	}
};