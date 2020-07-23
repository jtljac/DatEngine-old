#pragma once
#include <iostream>
#include <Dat-VFS/DatVFS/DataPtr.h>
#include "../BaseAsset.h"

class VertShader : public BaseAsset {
	DataPtr data;
public:
	VertShader(DataPtr& Data) : data(Data) {};
};