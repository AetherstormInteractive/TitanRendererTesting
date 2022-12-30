#include "VulkanRenderer.h"

int VulkanRenderer::Initialize(nlohmann::json configFile, int windowMode)
{
	//init SDL2
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}

	//create sdl2 window with vulkan context at center screen
	window = SDL_CreateWindow("Vulkan Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, configFile["Display"]["Width"], configFile["Display"]["Height"], SDL_WINDOW_VULKAN | SDL_WINDOW_SHOWN);

	//null check if window exists
	if (window == NULL)
	{
		std::cout << "ERROR: No Vulkan API Found!" << std::endl;
		return -1;
	}
	else
	{
		std::cout << "Vulkan Initialization" << std::endl;
	}

	return 0;
}

void VulkanRenderer::Update(float deltaTime, int windowMode)
{
	//update window mode
	switch (windowMode) {
	case 0:
		SDL_SetWindowFullscreen(window, 0);
		break;
	case 1:
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
		break;
	case 2:
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
		break;
	}
}

void VulkanRenderer::Draw()
{

}

void VulkanRenderer::Shutdown()
{
	//destroy window and shutdown sdl2
	SDL_DestroyWindow(window);
	SDL_Quit();
}