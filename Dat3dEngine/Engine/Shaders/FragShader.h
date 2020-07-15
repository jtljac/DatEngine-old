#pragma once
#include <iostream>
#include <Dat-VFS/DatVFS/DataPtr.h>

class FragShader {
	DataPtr data;
public:
	FragShader(DataPtr Data) : data(Data) {};

	void setData(DataPtr Data) {
		data = Data;
	};
};