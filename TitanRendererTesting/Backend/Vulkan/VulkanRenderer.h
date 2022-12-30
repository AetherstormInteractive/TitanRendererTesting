#if defined(WIN32) || defined(LINUX) 

#ifndef VULKAN_RENDERER_H
#define VULKAN_RENDERER_H

#include <stdio.h>
#include <stdlib.h>
#include <optional>
#include <set>
#include <cstdint>
#include <limits>
#include <algorithm>

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_syswm.h>
#include <SDL_vulkan.h>

#include <vulkan/vulkan.h>
#define VK_USE_PLATFORM_WIN32_KHR

#include <nlohmann/json.hpp>

#include "../../Renderer.h"

class VulkanRenderer : public Renderer
{
public:
	int Initialize(nlohmann::json configFile, int windowMode);
	void Update(float deltaTime, int windowMode);
	void Draw();
	void Shutdown();
};
#endif
#endif