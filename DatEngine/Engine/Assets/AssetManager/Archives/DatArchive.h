#pragma once
#include <DatVFS/DatVFSCommon.h>
#include <DatArchive.h>

#include <memory>
#include <utility>

/**
 * An IDVFSFile implementation for DatArchive files, allowing access to files inside the archive
 * Not threadsafe, as all the files in the DVFS for each archive file use the same DatArchive instance.
 * TODO: Make Threadsafe using locks
 */
class DVFSArchiveFile : public IDVFSFile {
    // A shared pointer to the archive file, allowing many archive files to use the same file pointer
    // This isn't thread safe as
	const std::shared_ptr<DatFile> archiveFile;
    const std::string archivePath;
public:
	DVFSArchiveFile(std::string archivePath, std::shared_ptr<DatFile> ArchiveFile) : archivePath(std::move(archivePath)), archiveFile(std::move(ArchiveFile)) {
        fileSize = this->archiveFile->getFileHeader(this->archivePath).size();
    }

    [[nodiscard]] bool isValidFile() const override {
        return archiveFile->contains(archivePath);
    }

    bool getContent(char* buffer) const override {
		return archiveFile->getFile(archivePath, buffer);
	}
};

/**
 * A IDVFSInserter implementation that inserts all the files in a DatArchive file to the VFS
 */
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