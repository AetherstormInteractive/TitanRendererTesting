#include "VulkanRenderer.h"


int VulkanRenderer::Initialize(nlohmann::json configFile, bool is_fullscreen)
{
	window = SDL_CreateWindow("Vulkan Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, configFile["Display"]["Width"], configFile["Display"]["Height"], SDL_WINDOW_VULKAN | SDL_WINDOW_SHOWN);
	std::cout << "Vulkan Initialization" << std::endl;
	return 0;
}

void VulkanRenderer::Update(nlohmann::json configFile, bool is_fullscreen)
{
	SDL_SetWindowFullscreen(window, is_fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
}

void VulkanRenderer::Shutdown()
{

}
