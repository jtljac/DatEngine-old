#pragma once
#include "AssetFactory.h"
#include "../Assets/BaseAsset.h"
#include "../Assets/Shaders/VertShader.h"

class VertShaderFactory : public AssetFactory {
public:
	BaseAsset* load(std::vector<char>& data) override {
		return new VertShader(data);
	}
};