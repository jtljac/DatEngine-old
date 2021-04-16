#include "../FileUtilities.h"
#include <exception>
#include <string>
#include <filesystem>


#ifdef _WIN32
#include <windows.h>
#include <shlobj.h>
#elif __linux__
#include <libgen.h>
#include <unistd.h>
#include <climits>
#include <sys/types.h>
#include <pwd.h>
#endif

// Create Files
std::ofstream FileUtilities::createFile(std::filesystem::path filePath) {
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
std::string FileUtilities::readWholeFile(std::filesystem::path filePath)
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

std::filesystem::path FileUtilities::getDataPath() {
	std::filesystem::path dest;
#ifdef _WIN32
	// If windows, request the documents path from the OS
	wchar_t* documents;
	HRESULT result = SHGetKnownFolderPath(FOLDERID_Documents, SHGFP_TYPE_CURRENT, NULL, &documents);
	if (result == 0) {
		dest = std::filesystem::path(documents);
		CoTaskMemFree(documents);
	}
	else {
		return std::filesystem::path();
	}
#elif __linux__
	// If Linux ask for Data documents env
	
	std::string homeDir = getenv("XDG_DATA_HOME");
	if (homeDir.empty()) {
		homeDir = getenv("HOME");
		if (homeDir.empty()) {
			// If not defined, get it from pwd
            homeDir = getpwuid(getuid())->pw_dir;
		}
		homeDir += "/.config";
	}
    dest = std::filesystem::path(homeDir);

#endif
	return dest / "GAMENAME"; // TODO: Game name
}

std::filesystem::path FileUtilities::getGamePath() {
	std::filesystem::path dest;
#ifdef _DEBUG
	dest = "./";
#elif _WIN32
	wchar_t buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	dest = std::filesystem::path(buffer);
#elif __linux__
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    const char *path;
    if (count != -1) {
        path = dirname(result);
    }
#endif
	return dest;
}

std::filesystem::path FileUtilities::getResourcesPath() {
	return getGamePath() / "Resources";
}