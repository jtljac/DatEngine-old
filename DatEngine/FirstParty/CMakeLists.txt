cmake_minimum_required (VERSION 3.17)

add_subdirectory(Dat-Archive)
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC "Dat-VFS")