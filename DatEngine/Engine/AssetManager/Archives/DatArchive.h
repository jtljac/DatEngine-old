#pragma once
#include <DatVFS/DatVFSCommon.h>
#include <DatArchive.h>

#include <memory>
#include <utility>

class DVFSArchiveFile : public IDVFSFile {
	const std::shared_ptr<DatFile> archiveFile;
    const std::string archivePath;
public:
	DVFSArchiveFile(std::string archivePath, std::shared_ptr<DatFile> ArchiveFile) : archivePath(std::move(archivePath)), archiveFile(std::move(ArchiveFile)) {
        fileSize = ArchiveFile->getFileHeader(archivePath).size();
    }

    [[nodiscard]] bool isValidFile() const override {
        return archiveFile->contains(archivePath);
    }

    bool getContent(char* buffer) const override {
		return archiveFile->getFile(archivePath, buffer);
	}
};

class DVFSDatArchiveInserter : public IDVFSInserter {
	std::shared_ptr<DatFile> archive;
public:
    explicit DVFSDatArchiveInserter(const std::filesystem::path& filePath, const std::string& mountPoint = "") : IDVFSInserter(mountPoint) {
		archive = std::make_shared<DatFile>(filePath);
	}

	[[nodiscard]] std::vector<pair> getAllFiles() const override {
		std::vector<std::string> paths = archive->getListOfFiles();
		std::vector<pair> files(archive->size());

		for (const std::string& path : paths) {
			files.emplace_back(path, new DVFSArchiveFile(path, archive));
		}

		return files;
	}
};