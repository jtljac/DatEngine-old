#pragma once
#include <Dat-VFS/DatVFS/DatVFSCommon.h>
#include <Dat-Archive/DatArchive.h>

class DVFSArchiveFile : public DVFSFile {
	std::shared_ptr<DatFile> archiveFile;
public:
	DVFSArchiveFile(std::string Dest, std::shared_ptr<DatFile> ArchiveFile) : DVFSFile(Dest) {
		archiveFile = ArchiveFile;
	}

	bool loadFile() {
		// Ensure its not already loaded
		if (data.dataLoaded()) {
			std::cout << "Tried to load file while already loaded, ignoring" << std::endl;
			return false;
		}

		// Pointer to put the data
		char* theData;

		// request the data from the archive file
		archiveFile->getFile(fileLocation.string(), &theData);

		// Set the dataPtr to the new data
		data.setData(theData);

		data.setLoaded(true);
		return true;
	}
};

class DatVFSArchive : public VFSArchive{
	std::shared_ptr<DatFile> archive;
public:
	DatVFSArchive(std::string filePath) {
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