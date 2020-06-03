#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <stdexcept>
#include <utf8.h>

//class Path {
//private:
//	std::u32string path;
//	bool valid = true;
//
//	void fixSlashes() {
//		int index;
//		while ((index = path.find_first_of(U'\\')) != -1) {
//			if (index == 0) path.erase(0,1);
//			else path[index] = U'/';
//		}
//	}
//public:
//	Path() {
//		valid = false;
//	}
//	Path(std::u32string Path) {
//		path = Path;
//	}
//
//	Path(std::u16string Path) {
//		std::string tempPath;
//		utf8::utf16to8(Path.begin(), Path.end(), std::back_inserter(tempPath));
//		utf8::utf8to32(tempPath.begin(), tempPath.end(), std::back_inserter(path));
//		fixSlashes();
//	}
//
//	Path(std::string Path) {
//		utf8::utf8to32(Path.begin(), Path.end(), std::back_inserter(path));
//		fixSlashes();
//	}
//
//	Path getSubPath(int index) {
//		if (std::count(path.begin(), path.end(), '/') >= index) throw std::out_of_range("Index out of range");
//		fixSlashes();
//
//	}
//
//	bool isValid() {
//		return valid;
//	}
//
//	bool isDirectory() {
//		return std::filesystem::is_directory(path);
//	}
//
//	std::u32string getPath() {
//		return path;
//	}
//
//	std::string getPathU8() {
//		std::string tempPath;
//		utf8::utf32to8(path.begin(), path.end(), std::back_inserter(tempPath));
//		return tempPath;
//	}
//
//	std::u16string getPathU16() {
//		std::string u8TempPath = getPathU8();
//		std::u16string tempPath;
//
//		utf8::utf8to16(u8TempPath.begin(), u8TempPath.end(), std::back_inserter(tempPath));
//
//		return tempPath;
//	}
//
//	Path operator+(std::u32string string) {
//		return Path(path + string);
//	}
//
//	Path operator+(std::u16string string) {
//		std::string u8String;
//		std::u32string u32String;
//		utf8::utf16to8(string.begin(), string.end(), std::back_inserter(u8String));
//		utf8::utf8to32(u8String.begin(), u8String.end(), std::back_inserter(u32String));
//
//		return Path(path + u32String);
//	}
//
//	Path operator+(std::string string) {
//		std::u32string u32String;
//		utf8::utf8to32(string.begin(), string.end(), std::back_inserter(u32String));
//		return Path(path + u32String);
//	}
//
//	friend Path operator+(const Path& path1, const Path& path2) {
//		return Path(path1.path + path2.path);
//	}
//
//	friend std::ostream& operator<< (std::ostream& stream, Path path) {
//		if (path.valid) return stream << path.getPathU8();
//		else return stream << "Bad Path";
//	}
//};

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