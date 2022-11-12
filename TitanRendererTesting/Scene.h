#include <iostream>
#include <fstream>

#include <entt/entt.hpp>

#define USE_OPENGL
#if defined(USE_OPENGL)
#include "Backend/OpenGL/OpenGLRenderer.h"
#elif defined(USE_D3D11)
#include "Backend/D3D11/D3D11Renderer.h"
#elif defined(USE_D3D12)
#include "Backend/D3D12/D3D12Renderer.h"
#elif defined(USE_VULKAN)
#include "Backend/Vulkan/VulkanRenderer.h"
#elif defined(USE_METAL)
#include "Backend/Metal/MetalRenderer.h"
#endif

using json = nlohmann::json;
class Scene
{
public:
	json configFile;
	entt::registry registry;
#if defined(USE_OPENGL)
	Renderer::OpenGLRenderer renderer;
#elif defined(USE_D3D11)
	Renderer::D3D11Renderer renderer;
#elif defined(USE_D3D12)
	Renderer::D3D12Renderer renderer;
#elif defined(USE_VULKAN)
	Renderer::VulkanRenderer renderer;
#elif defined(USE_METAL)
	Renderer::MetalRenderer renderer;
#endif
	GLFWwindow* window;
	bool is_fullscreen = false;

	int SceneStart();
	void SceneUpdate();
	int SceneEnd();

	void CreateEntity(entt::entity entity);
	void DeleteEntity(entt::entity entity);

private:
	std::vector<entt::entity> entities;
};
