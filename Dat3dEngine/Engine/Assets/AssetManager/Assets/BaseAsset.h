#pragma once
#include <Dat-VFS/DatVFS/DataPtr.h>

class BaseAsset {
public:
	bool cacheable = false;


	virtual ~BaseAsset() = default;
};