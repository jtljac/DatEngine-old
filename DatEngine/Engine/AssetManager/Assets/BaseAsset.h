#pragma once
#include <DatVFS/DataPtr.h>

/**
 * An asset that can be stored on and loaded from the disk.
 */
class BaseAsset {
public:
	const bool cacheable;

	BaseAsset() : cacheable(false) {};

	BaseAsset(bool Cacheable) : cacheable(Cacheable) {}


	virtual ~BaseAsset() = default;
};