cmake_minimum_required (VERSION 3.17)

# Includes
target_include_directories(${PROJECT_NAME} PUBLIC "GLFW/Include" "Vulkan/Include" "GLM/Include" "ZLib/Include" "nlohmann/Include")

# Link Directories
target_link_directories (${PROJECT_NAME} PUBLIC "Vulkan/Lib" "ZLib/Lib" "GLFW/Lib")

# Add libraries
target_link_libraries (${PROJECT_NAME} PUBLIC glfw3 vulkan-1 zlib)