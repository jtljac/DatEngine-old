target_sources(DatEngine
				PUBLIC
					"EngineConfig.h")

configure_file (EngineDetails.h.in EngineDetails.h)
target_include_directories (DatEngine PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")