# CMakeList.txt : CMake project for TitanVulkanTesting, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (TitanVulkanTesting "Scene.cpp" "Scene.h" "main.cpp" "../3rdparty/glad/src/glad.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TitanVulkanTesting PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(TitanVulkanTesting glfw nlohmann_json bgfx glad)

# TODO: Add tests and install targets if needed.
