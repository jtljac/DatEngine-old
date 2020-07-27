#pragma once

#include "../Assets/BaseAsset.h"
class AssetFactory {
public:
	virtual BaseAsset* load(DataPtr& data) {
		return new BaseAsset();
	}
};