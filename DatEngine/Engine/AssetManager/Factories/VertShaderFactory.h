#pragma once
#include "AssetFactory.h"
#include "../Assets/BaseAsset.h"
#include "../Assets/Shaders/VertShader.h"

/**
 * An asset factory for creating Vertex Shaders
 */
class VertShaderFactory : public AssetFactory {
public:
	BaseAsset* load(std::vector<char>& data) override {
		return new VertShader(data);
	}
};