#include "../FileUtilities.h"
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
	// Log::info("File Utilities", "Created File " + filename + " at " + directory);
	return std::move(theFile);
}

//Directory Getters
std::filesystem::path FileUtilities::getResourcesPath() {
	return getGamePath() / "Resources";
}