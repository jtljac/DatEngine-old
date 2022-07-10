#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>

namespace FileUtilities {
	// Directory Getters
    /**
     * @return The path that user data, like config and savegames, are stored
     */
	std::filesystem::path getDataPath();

    /**
     * @return The path that contains the game
     */
	std::filesystem::path getGamePath();
    /**
     * @return The path that contains the game's resources
     */
	std::filesystem::path getResourcesPath();

	// Create Files
    /**
     * Creates a file at the given path, creating all subdirectories required
     * @param filePath The path to the file
     * @return an outputStream for the newly created file
     */
	std::ofstream createFile(const std::filesystem::path& filePath);
}