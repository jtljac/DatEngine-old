# Asset Manager
target_sources (DatEngine 
		PUBLIC
			"AssetManager/AssetManager.h"
		PRIVATE
			"AssetManager/Source/AssetManager.cpp"
			"AssetManager/Archives/DatArchive.h"
)


# Assets
target_sources (DatEngine 
		PUBLIC
			"BaseAsset.h"
			"Shaders/FragShader.h"
			"Shaders/VertShader.h"
)

# Factories
target_sources (DatEngine 
		PUBLIC
			"BaseAssetFactory.h"
			"Shaders/FragShaderFactory.h"
			"Shaders/VertShaderFactory.h"
)