﻿#include <iostream>
#include <fstream>

#include <nlohmann/json.hpp>
#include <entt/entt.hpp>

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
	Scene()
	{
		std::ifstream i("config.ini");
		i >> configFile;
		if (configFile["Display"]["Backend"] == "OpenGL")
		{
			api = new OpenGLRenderer();
		}
		else if (configFile["Display"]["Backend"] == "Vulkan")
		{
			api = new VulkanRenderer();
		}
		else if (configFile["Display"]["Backend"] == "DirectX11")
		{
			api = new D3D11Renderer();
		}
		else if (configFile["Display"]["Backend"] == "DirectX12")
		{
			api = new D3D12Renderer();
		}
		else if (configFile["Display"]["Backend"] == "Metal")
		{
			api = new MetalRenderer();
		}
	}
	
	entt::registry registry;

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
