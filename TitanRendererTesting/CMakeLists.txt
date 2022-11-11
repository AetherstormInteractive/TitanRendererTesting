# CMakeList.txt : CMake project for TitanVulkanTesting, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/")
# Add source to this project's executable.
add_executable (TitanRendererTesting "Scene.cpp" "Scene.h" "main.cpp" "../3rdparty/glad/src/glad.c"
"Backend/BGFX/BGFXRenderer.cpp" "Backend/BGFX/BGFXRenderer.h" "Backend/BGFX/BGFXModel.cpp" "Backend/BGFX/BGFXModel.h" "Backend/BGFX/BGFXMesh.cpp" "Backend/BGFX/BGFXMesh.h"
#"Backend/OpenGL/OpenGLRenderer.cpp" "Backend/OpenGL/OpenGLRenderer.h" "Backend/OpenGL/OpenGLModel.cpp" "Backend/OpenGL/OpenGLModel.h" "Backend/OpenGL/OpenGLMesh.cpp" "Backend/OpenGL/OpenGLMesh.h" "Backend/OpenGL/OpenGLShader.h" "Backend/OpenGL/OpenGLCamera.h"
)

target_link_libraries(TitanRendererTesting glfw nlohmann_json bgfx bx bimg glad EnTT glm assimp tinyobjloader)

include_directories(${CMAKE_SOURCE_DIR}/3rdparty/stb)
link_directories(${CMAKE_SOURCE_DIR}/3rdparty/stb) 


# TODO: Add tests and install targets if needed.
