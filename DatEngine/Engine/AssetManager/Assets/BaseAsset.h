#pragma once
#include <Dat-VFS/DatVFS/DataPtr.h>

class BaseAsset {
public:
	const bool cacheable;

	BaseAsset() : cacheable(false) {};

	BaseAsset(bool Cacheable) : cacheable(Cacheable) {}


	virtual ~BaseAsset() = default;
};