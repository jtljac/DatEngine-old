#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <stdexcept>

namespace FileUtilities {
	// Read File
	std::string readWholeFile(const std::filesystem::path& filePath);
	std::string getFileContent(std::fstream& file);
	std::string getFileContent(std::ifstream& file);
	std::string getStreamContents(std::istream& stream);

	// Directory Getters
	std::filesystem::path getDataPath();
	std::filesystem::path getGamePath();
	std::filesystem::path getResourcesPath();

	// Create Files
	std::ofstream createFile(const std::filesystem::path& filePath);
}