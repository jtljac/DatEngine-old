#include <Utilities/FileUtilities.h>
#include <filesystem>

#include <Windows.h>
#include <ShlObj.h>

//Directory Getters
std::filesystem::path FileUtilities::getDataPath() {
	std::filesystem::path dest;

	// If windows, request the documents path from the OS
	wchar_t* documents;
	HRESULT result = SHGetKnownFolderPath(FOLDERID_Documents, SHGFP_TYPE_CURRENT, nullptr, &documents);
	if (result == 0) {
		dest = std::filesystem::path(documents);
		CoTaskMemFree(documents);
	}
	else {
		return {};
	}

	return dest / "GAMENAME"; // TODO: Game name
}

std::filesystem::path FileUtilities::getGamePath() {
	std::filesystem::path dest;
#ifdef _DEBUG
	dest = "./";
#else
	char buffer[MAX_PATH];
	GetModuleFileName(nullptr, buffer, MAX_PATH);
	dest = std::filesystem::path(buffer);
#endif
	return dest;
}