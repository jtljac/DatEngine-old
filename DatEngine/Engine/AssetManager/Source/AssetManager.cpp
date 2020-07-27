#include "../AssetManager.h"
#include "../Archives/DatArchive.h"

void AssetManager::populate() {
	Log::i(TAG, "Loading archives");
	addArchives();

	// Make not-constant
	if (true) {
		Log::i(TAG, "Loading Loose Files");
		addLooseFiles();
	}
}

void AssetManager::addArchives()
{
	std::filesystem::path resourcesPath = FileUtilities::getResourcesPath();

	for (std::filesystem::directory_entry entry : std::filesystem::directory_iterator(resourcesPath)) {
		if (!entry.is_directory() && entry.path().extension() == "dat") {
			Log::i(TAG, "Adding archive " + entry.path().string());

			DatVFSArchive archiveFile = DatVFSArchive(entry.path());
			fileTree->addArchive(archiveFile);
		}
	}
}

void AssetManager::addLooseFiles()
{
	std::filesystem::path resourcesPath = FileUtilities::getResourcesPath();

	Log::i(TAG, "Adding loose files in " + resourcesPath.string());

	std::string regex;

	// Build regex string that looks like ^(.(?!.*\\.(dat|...|...)$))* to exclude unwanted file extensions
	regex = "^(.(?!.*\\.(dat";
	if (excludedExtensions.size() != 0) {
		for (const std::string& extension : excludedExtensions) {
			regex += "|" + extension;
		}
	}
	regex += ")$))*";


	// Add everything in the resources path that isn't an excluded file
	fileTree->addFolder(resourcesPath, true, true, regex);
}

AssetManager::AssetManager() {
	fileTree = new DatVFS;
	populate();
	fileTree->tree();
}

AssetManager::~AssetManager() {
	delete fileTree;
}
