# Utilities
target_sources (DatEngine
				PUBLIC
					"Console.h"
					"FileUtilities.h"
					"Logging.h"
				PRIVATE
					"Source/FileUtilities.cpp")
# Exceptions
target_sources (DatEngine 
				PUBLIC
					"Exceptions/UnknownResourceFactoryException.h")