#include "../AssetManager.h"
#include "../Archives/DatArchive.h"

void AssetManager::populate() {
	Log::info(TAG, "Loading archives");
	addArchives();

	// TODO: Config: Make not-constant
	if (true) {
		Log::info(TAG, "Loading Loose Files");
		addLooseFiles();
	}
}

void AssetManager::addArchives()
{
	std::filesystem::path resourcesPath = FileUtilities::getResourcesPath();

	for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(resourcesPath)) {
		if (!entry.is_directory() && entry.path().extension() == "dat") {
			Log::info(TAG, "Adding archive " + entry.path().string());

			DVFSDatArchiveInserter archiveFile(entry.path());
			fileTree->insertFiles(archiveFile);
		}
	}
}

void AssetManager::addLooseFiles()
{
	std::filesystem::path resourcesPath = FileUtilities::getResourcesPath();

	Log::info(TAG, "Adding loose files in " + resourcesPath.string());

	// Build regex string that looks like ^(.(?!.*\\.(dat|...|...)$))* to exclude unwanted file extensions
    std::string regex = "^(.(?!.*\\.(dat";
	if (!excludedExtensions.empty()) {
		for (const std::string& extension : excludedExtensions) {
			regex += "|" + extension;
		}
	}
	regex += ")$))*";


	// Add everything in the resources path that isn't an excluded file
    fileTree->insertFiles(DVFSLooseFilesInserterFiltered(resourcesPath, regex));
}

AssetManager::AssetManager() {
	fileTree = new DatVFS;
	populate();
	fileTree->tree();
}

AssetManager::~AssetManager() {
	delete fileTree;
}
