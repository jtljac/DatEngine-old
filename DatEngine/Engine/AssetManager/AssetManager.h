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

	void populate();

	void addArchives();
	void addLooseFiles();


public:
	AssetManager();
	~AssetManager();

	void addExtensionExclusion(const std::string extension) {
		excludedExtensions.insert(extension);
	}
	
	void addExtensionExclusions(std::vector<std::string> &extensions) {
		for (const std::string& extension : extensions) {
			excludedExtensions.insert(extension);
		}
	}

	template<class AssetType>
	void registerFactory(AssetFactory* Factory) {
		factories[typeid(AssetType)] = Factory;
	}

	template<class T>
	T* loadAsset(const std::string& thePath) {
		std::vector<char> data = fileTree->getFile(thePath)->getContent();
		AssetFactory* factory;

		if (factories.count(typeid(T)) == 0) {
            Log::warn(TAG, "Failed to load factory for type: " + std::string(typeid(T).name()));
			return nullptr;
		}

		factory = factories.at(typeid(T));

		BaseAsset* asset = factory->load(data);

		// Cast the asset to the requested format, as the factory should return the class as the base class
		T* actualAsset = dynamic_cast<T*>(asset);

		// Ensure cast was successful
		assert(actualAsset);

		Log::info(TAG, "Loaded asset " + thePath);

		return actualAsset;
	}
};