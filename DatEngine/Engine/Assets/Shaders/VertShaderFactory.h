#pragma once
#include <Assets/BaseAssetFactory.h>
#include "VertShader.h"

/**
 * An asset factory for creating Vertex Shaders
 */
class VertShaderFactory : public BaseAssetFactory {
public:
	BaseAsset* load(std::vector<char>& data) override {
		return new VertShader(data);
	}
};