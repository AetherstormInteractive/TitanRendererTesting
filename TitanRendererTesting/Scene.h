#include <iostream>
#include <fstream>

#include <nlohmann/json.hpp>
#include <entt/entt.hpp>
#include <SDL.h>

#include "Backend/OpenGL/OpenGLRenderer.h"
#include "Backend/Vulkan/VulkanRenderer.h"
#include "Backend/Metal/MetalRenderer.h"
#include "Backend/D3D11/D3D11Renderer.h"
#include "Backend/D3D12/D3D12Renderer.h"
#include "Renderer.h"


using json = nlohmann::json;

class Scene
{
public:
	json configFile;

	Renderer* api = nullptr;
	OpenGLRenderer* openglrenderer = new OpenGLRenderer();
	VulkanRenderer* vulkanrenderer = new VulkanRenderer();
	D3D11Renderer* d3d11renderer = new D3D11Renderer();
	D3D12Renderer* d3d12renderer = new D3D12Renderer();
	MetalRenderer* metalrenderer = new MetalRenderer();
	Scene()
	{
		std::ifstream i("config.ini");
		i >> configFile;
		if (configFile["Display"]["Backend"] == "OpenGL")
		{
			api = openglrenderer;
		}
		else if (configFile["Display"]["Backend"] == "Vulkan")
		{
			api = vulkanrenderer;
		}
		else if (configFile["Display"]["Backend"] == "DirectX11")
		{
			api = d3d11renderer;
		}
		else if (configFile["Display"]["Backend"] == "DirectX12")
		{
			api = d3d12renderer;
		}
		else if (configFile["Display"]["Backend"] == "Metal")
		{
			api = metalrenderer;
		}
	}
	
	entt::registry registry;

	SDL_Window* window;
	SDL_Surface* screenSurface;

	bool is_fullscreen = false;

	int SceneStart();
	void SceneUpdate();
	int SceneEnd();

	void CreateEntity(entt::entity entity);
	void DeleteEntity(entt::entity entity);

private:
	std::vector<entt::entity> entities;
};
