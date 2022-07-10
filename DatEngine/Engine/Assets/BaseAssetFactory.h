#pragma once

#include "Assets/BaseAsset.h"

/**
 * An abstract class used to take raw data from the disk and construct a specific Asset with it
 * @see BaseAsset
 */
class BaseAssetFactory {
public:
    virtual ~BaseAssetFactory() = default;

    /**
     * Convert the given raw data into the asset
     * @param data The raw data used to construct the Asset
     * @return A pointer to the asset constructed from the data, or nullptr if construction failed
     */
	virtual BaseAsset* load(std::vector<char>& data) {
		return new BaseAsset();
	}
};