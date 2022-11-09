# CMakeList.txt : CMake project for TitanVulkanTesting, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/")
# Add source to this project's executable.
add_executable (TitanVulkanTesting "Scene.cpp" "Scene.h" "main.cpp" "../3rdparty/glad/src/glad.c" "BGFXRenderer.cpp" "BGFXRenderer.h")

target_link_libraries(TitanVulkanTesting glfw nlohmann_json bgfx bx bimg glad EnTT)


# TODO: Add tests and install targets if needed.
