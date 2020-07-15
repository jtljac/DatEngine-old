#pragma once
#include <iostream>
#include <Dat-VFS/DatVFS.h>
#include <Engine/Utilities/FileUtilities.h>
#include <Engine/Shaders/FragShader.h>
#include <Engine/Shaders/VertShader.h>

class AssetManager {
private:
	DatVFS* fileTree = nullptr;

	void populate();

	void addArchives();
	void addLooseFiles();

public:
	AssetManager();
	~AssetManager();

	// Load Assets
	void loadFragShader(std::string thePath, FragShader* shaderFile) {
		DataPtr data = fileTree->getFile(thePath)->getFile();
		
	}

	void loadVertShader(std::string thePath, VertShader* shaderFile) {
		shaderFile->setData(fileTree->getFile(thePath)->getFile());
		
	}
};