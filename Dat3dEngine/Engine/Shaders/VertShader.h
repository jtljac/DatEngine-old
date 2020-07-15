#pragma once
#include <iostream>
#include <Dat-VFS/DatVFS/DataPtr.h>

class VertShader {
	DataPtr data;
public:
	VertShader() {};
	
	void setData(DataPtr Data) { 
		data = DataPtr(Data);
	};
};