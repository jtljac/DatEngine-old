#include "../FileUtilities.h"
#include <exception>
#include <string>
#include <filesystem>

// Create Files
std::ofstream FileUtilities::createFile(const std::filesystem::path& filePath) {
	// Define File
	std::ofstream theFile;
	// If the directory doesn't exist, create it
	if (!std::filesystem::exists(filePath.parent_path())) {
		std::filesystem::create_directories(filePath.parent_path());
	}

	// Open File
	theFile.open(filePath);
	// Log::i("File Utilities", "Created File " + filename + " at " + directory);
	return std::move(theFile);
}

// Read Files
std::string FileUtilities::readWholeFile(const std::filesystem::path& filePath)
{
	// Open File
	std::ifstream theFile;
	std::string data;
	theFile.open(filePath);

	if (theFile) {
		// Read file contents
		data = getFileContent(theFile);
		theFile.close();
	}
	else {
		throw std::runtime_error("Failed to Find File");
	}
	return data;
}

std::string FileUtilities::getFileContent(std::ifstream& file)
{
	if (file.is_open()) {
		return getStreamContents(file);
	}
	else {
		throw std::runtime_error("File is not open");
		return "";
	}
}

std::string FileUtilities::getFileContent(std::fstream& file)
{
	if (file.is_open()) {
		return getStreamContents(file);
	}
	else {
		throw std::runtime_error("File is not open");
		return "";
	}
}

std::string FileUtilities::getStreamContents(std::istream& stream) {
	std::string line;
	std::string content;

	// Iterate through file
	while (getline(stream, line)) {
		content += line + "\n";
	}
	return content;
}

//Directory Getters
std::filesystem::path FileUtilities::getResourcesPath() {
	return getGamePath() / "Resources";
}