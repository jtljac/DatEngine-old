#include <Utilities/FileUtilities.h>
#include <exception>
#include <string>
#include <filesystem>

#include <libgen.h>
#include <unistd.h>
#include <climits>
#include <sys/types.h>
#include <pwd.h>

//Directory Getters

std::filesystem::path FileUtilities::getDataPath() {
	std::filesystem::path dest;
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

	return dest / "GAMENAME"; // TODO: Game name
}

std::filesystem::path FileUtilities::getGamePath() {
	std::filesystem::path dest;
#ifdef _DEBUG
	dest = "./";
#else
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    const char *path;
    if (count != -1) {
        path = dirname(result);
    }
#endif
	return dest;
}