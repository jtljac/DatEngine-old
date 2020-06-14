#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <stdexcept>
#include <utf8.h>

namespace FileUtilities {
	// Read File
	std::string readWholeFile(std::filesystem::path filePath);
	std::string getFileContent(std::fstream& file);
	std::string getFileContent(std::ifstream& file);
	std::string getStreamContents(std::istream& stream);

	// Directory Getters
	std::filesystem::path getDataPath();
	std::filesystem::path getGamePath();
	std::filesystem::path getResourcesPath();

	// Create Files
	std::ofstream createFile(std::filesystem::path filePath);
}