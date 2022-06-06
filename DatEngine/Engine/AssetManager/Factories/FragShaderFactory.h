#pragma once
#include "AssetFactory.h"
#include "../Assets/BaseAsset.h"
#include "../Assets/Shaders/FragShader.h"

/**
 * An Asset factory for creating Fragment Shaders
 */
class FragShaderFactory : public AssetFactory {
public:
	BaseAsset* load(std::vector<char>& data) override {
		return new FragShader(data);
	}
};