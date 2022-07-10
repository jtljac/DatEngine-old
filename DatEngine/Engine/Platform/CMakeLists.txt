# Subdirectories
if(WIN32)
	add_subdirectory ("Windows")
else(WIN32)
	add_subdirectory ("Posix")
endif(WIN32)