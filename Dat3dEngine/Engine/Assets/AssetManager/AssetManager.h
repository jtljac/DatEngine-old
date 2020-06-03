#pragma once
#include <Dat-VFS/DatVFS.h>
#include <Engine/Utilities/FileUtilities.h>

class AssetManager {
private:
	DatVFS* fileTree = nullptr;
	AssetManager() {
		fileTree = new DatVFS;
		// ^(.(?!.*\.(dat)$))*

	}
	~AssetManager() {
		delete fileTree;
	}

	void populate();

	void addArchives();
	void addLooseFiles();
};