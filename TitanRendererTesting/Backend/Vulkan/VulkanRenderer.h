#include <nlohmann/json.hpp>
#include <SDL.h>
#undef main

#include <vulkan/vulkan.h>
#include "../../Renderer.h"

class VulkanRenderer : public Renderer
{
public:
	int Setup(SDL_Window* win, nlohmann::json configFile, bool is_fullscreen);
	void Run(nlohmann::json configFile, bool is_fullscreen);
	void Shutdown();
};