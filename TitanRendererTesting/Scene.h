﻿#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <fstream>

#include <nlohmann/json.hpp>
#include <entt/entt.hpp>

#include "Backend/OpenGL/OpenGLRenderer.h"
#include "Backend/Vulkan/VulkanRenderer.h"
#include "Backend/D3D11/D3D11Renderer.h"
#include "Backend/D3D12/D3D12Renderer.h"
#include "Backend/SDL2/SDL2Renderer.h"
#include "Backend/Metal/MetalRenderer.h"
#include "Renderer.h"


using json = nlohmann::json;

class Scene
{
public:
	json configFile;
	bool is_fullscreen = false;

	entt::registry registry;

	Renderer* api = nullptr;
	OpenGLRenderer* openglrenderer = new OpenGLRenderer();
	VulkanRenderer* vulkanrenderer = new VulkanRenderer();
	D3D11Renderer* d3d11renderer = new D3D11Renderer();
	D3D12Renderer* d3d12renderer = new D3D12Renderer();
	SDL2Renderer* sdl2renderer = new SDL2Renderer();
	MetalRenderer* metalrenderer = new MetalRenderer();

	std::string configPath = "config/engineConfig.ini";

	Scene()
	{
		std::ifstream i(configPath);
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
		else if (configFile["Display"]["Backend"] == "SDL2")
		{
			api = sdl2renderer;
		}
	}

	void processInput();
	int SceneStart();
	void SceneUpdate();
	int SceneEnd();

	void CreateEntity(entt::entity entity);
	void DeleteEntity(entt::entity entity);

private:
	std::vector<entt::entity> entities;
};
#endif
