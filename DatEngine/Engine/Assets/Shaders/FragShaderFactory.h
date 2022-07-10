#pragma once
#include <Assets/BaseAssetFactory.h>
#include "FragShader.h"

/**
 * An Asset factory for creating Fragment Shaders
 */
class FragShaderFactory : public BaseAssetFactory {
public:
	BaseAsset* load(std::vector<char>& data) override {
		return new FragShader(data);
	}
};