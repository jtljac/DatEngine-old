cmake_minimum_required (VERSION 3.17)

# Loose
# Includes
target_include_directories(${PROJECT_NAME} PUBLIC "GLM/Include" "nlohmann/Include")

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(GLFW)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)

# Vulkan
set(VULKAN_PATH $ENV{VULKAN_SDK} CACHE PATH "The path to the vulkan SDK")
target_include_directories(${PROJECT_NAME} PUBLIC ${VULKAN_PATH}/Include)
target_link_directories(${PROJECT_NAME} PUBLIC ${VULKAN_PATH}/Lib)
target_link_libraries(${PROJECT_NAME} PUBLIC vulkan-1)