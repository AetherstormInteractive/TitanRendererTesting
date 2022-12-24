# CMakeList.txt : CMake project for TitanVulkanTesting, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
add_definitions(-DGLFW_INCLUDE_NONE)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/")
# Add source to this project's executable.
IF(UNIX)

	add_executable (TitanRendererTesting "Scene.cpp" "Scene.h" "main.cpp" "../3rdparty/glad/src/glad.c"  
	"Renderer.h" "Renderer.cpp"
	"Backend/OpenGL/OpenGLRenderer.cpp" "Backend/OpenGL/OpenGLRenderer.h"
	"Backend/D3D11/D3D11Renderer.cpp" "Backend/D3D11/D3D11Renderer.h"
	"Backend/D3D12/D3D12Renderer.cpp" "Backend/D3D12/D3D12Renderer.h"
	"Backend/Metal/MetalRenderer.cpp" "Backend/Metal/MetalRenderer.h"
	"Backend/SDL2/SDL2Renderer.cpp" "Backend/SDL2/SDL2Renderer.h"
	"DefaultComponents.h")

	target_link_libraries(TitanRendererTesting nlohmann_json EnTT glm tinyobjloader SDL2::SDL2 SDL2::SDL2main)
elseif(NOT APPLE)
	find_package(Vulkan REQUIRED)
	add_executable (TitanRendererTesting "Scene.cpp" "Scene.h" "main.cpp" "../3rdparty/glad/src/glad.c"  
	"Renderer.h" "Renderer.cpp"
	"Backend/OpenGL/OpenGLRenderer.cpp" "Backend/OpenGL/OpenGLRenderer.h"
	"Backend/D3D11/D3D11Renderer.cpp" "Backend/D3D11/D3D11Renderer.h"
	"Backend/D3D12/D3D12Renderer.cpp" "Backend/D3D12/D3D12Renderer.h"
	"Backend/Vulkan/VulkanRenderer.cpp" "Backend/Vulkan/VulkanRenderer.h" 
	"Backend/SDL2/SDL2Renderer.cpp" "Backend/SDL2/SDL2Renderer.h"
	"DefaultComponents.h")

	target_link_libraries(TitanRendererTesting Vulkan::Vulkan nlohmann_json EnTT glm tinyobjloader SDL3)
	endif()

include_directories(${CMAKE_SOURCE_DIR}/3rdparty/stb ${CMAKE_SOURCE_DIR}/3rdparty/glad/include)
link_directories(${CMAKE_SOURCE_DIR}/3rdparty/stb) 


# TODO: Add tests and install targets if needed.
