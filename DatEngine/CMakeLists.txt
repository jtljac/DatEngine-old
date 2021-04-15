# CMakeList.txt : CMake project for DatEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.17)

IF(MSVC)
   ADD_DEFINITIONS(/arch:SSE)
ENDIF(MSVC)

# Add source to this project's executable.
add_executable (DatEngine "Test/test.cpp")

configure_file (EngineDetails.h.in EngineDetails.h)
target_include_directories (DatEngine PRIVATE "${PROJECT_BINARY_DIR}")
target_include_directories (DatEngine PUBLIC "Engine")
target_include_directories (DatEngine PUBLIC "Editor")

# Add ThirdParty stuff
add_subdirectory ("ThirdParty")

# Add First Party Stuff
add_subdirectory ("FirstParty")

# Start Adding subfiles
add_subdirectory ("Engine")
add_subdirectory ("Editor")

add_custom_command(TARGET DatEngine POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       "${CMAKE_CURRENT_SOURCE_DIR}/Resources/" "$<TARGET_FILE_DIR:DatEngine>/Resources")
