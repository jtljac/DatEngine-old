#pragma once
#include <DatVFS/DatVFSCommon.h>
#include <DatArchive.h>

class DVFSArchiveFile : public DVFSFile {
	std::shared_ptr<DatFile> archiveFile;
public:
	DVFSArchiveFile(std::filesystem::path Dest, std::shared_ptr<DatFile> ArchiveFile) : DVFSFile(Dest), archiveFile(ArchiveFile) {}

	std::vector<char> getFile() override {
		

		// Pointer to put the data
		char* theData;

		unsigned int dataSize;

		// return the data from the archive file
		return archiveFile->getFile(fileLocation.string());
	}
};

class DatVFSArchive : public VFSArchive{
	std::shared_ptr<DatFile> archive;
public:
	DatVFSArchive(std::filesystem::path filePath) {
		archive = std::shared_ptr<DatFile>(new DatFile(filePath));
	}

	std::vector<std::pair<Path, DVFSFile*>> getFiles() override {
		std::vector<std::string> paths = archive->getFiles();
		std::vector<std::pair<Path, DVFSFile*>> files;

		for (std::string path : paths) {
			files.push_back(std::make_pair<Path, DVFSFile*>(std::filesystem::path(path), new DVFSArchiveFile(path, archive)));
		}

		return files;
	}
};