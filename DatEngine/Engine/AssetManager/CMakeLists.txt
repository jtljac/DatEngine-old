# Asset Manager
target_sources (DatEngine 
				PUBLIC 
					"AssetManager.h"
				PRIVATE
					"Source/AssetManager.cpp")

# Archives
target_sources (DatEngine 
				PUBLIC
					"Archives/DatArchive.h")

# Assets
target_sources (DatEngine 
				PUBLIC 
					"Assets/BaseAsset.h"
					"Assets/Shaders/FragShader.h"
					"Assets/Shaders/VertShader.h")

# Factories
target_sources (DatEngine 
				PUBLIC
					"Factories/AssetFactory.h"
					"Factories/FragShaderFactory.h")