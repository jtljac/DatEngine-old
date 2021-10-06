cmake_minimum_required (VERSION 3.17)

add_subdirectory(Dat-Archive)
target_link_libraries(DatEngine PUBLIC DatArchive)

add_subdirectory(Dat-VFS)
target_link_libraries(DatEngine PUBLIC DatVFS)