#pragma once

#include "../Assets/BaseAsset.h"
class AssetFactory {
public:
	virtual BaseAsset* load(std::vector<char>& data) {
		return new BaseAsset();
	}
};