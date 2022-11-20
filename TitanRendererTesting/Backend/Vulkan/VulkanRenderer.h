#ifndef VULKAN_RENDERER_H
#define VULKAN_RENDERER_H

#include <vulkan/vulkan.h>

#include <SDL.h>
#undef main

#include <nlohmann/json.hpp>

#include "../../Renderer.h"

class VulkanRenderer : public Renderer
{
public:
	int Initialize(nlohmann::json configFile, bool is_fullscreen);
	void Update(nlohmann::json configFile, bool is_fullscreen);
	void Shutdown();
};
#endif