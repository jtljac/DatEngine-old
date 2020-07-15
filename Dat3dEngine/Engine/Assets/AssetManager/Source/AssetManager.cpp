#include "../AssetManager.h"
#include "../Archives/DatArchive.h"

void AssetManager::populate() {
	addArchives();

	addLooseFiles();
}

void AssetManager::addArchives()
{
	std::filesystem::path resourcesPath = FileUtilities::getResourcesPath();

	for (std::filesystem::directory_entry entry : std::filesystem::directory_iterator(resourcesPath)) {
		if (!entry.is_directory() && entry.path().extension() == "dat") {
			DatVFSArchive archiveFile = DatVFSArchive(entry.path());
			fileTree->addArchive(archiveFile);
		}
	}
}

void AssetManager::addLooseFiles()
{
	std::filesystem::path resourcesPath = FileUtilities::getResourcesPath();
	fileTree->addFolder(resourcesPath, true, true, "^(.(?!.*\\.(dat)$))*");
}

AssetManager::AssetManager() {
	fileTree = new DatVFS;
	populate();
	fileTree->tree();
}

AssetManager::~AssetManager() {
	delete fileTree;
}
