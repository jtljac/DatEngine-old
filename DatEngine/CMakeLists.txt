# CMakeList.txt : CMake project for DatEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.17)

# Add source to this project's executable.
add_executable (DatEngine "Test/test.cpp" "Engine/Maths/Vectors/Vecs.h")

configure_file (EngineDetails.h.in EngineDetails.h)
target_include_directories (DatEngine PRIVATE "${PROJECT_BINARY_DIR}")
target_include_directories (DatEngine PUBLIC "Engine")

# Add ThirdParty stuff
add_subdirectory ("ThirdParty")

# Add First Party Stuff
target_include_directories (DatEngine PUBLIC "FirstParty")

add_subdirectory ("Engine")

add_custom_command(TARGET DatEngine POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       "${CMAKE_CURRENT_SOURCE_DIR}/Resources/" "$<TARGET_FILE_DIR:DatEngine>/Resources")
