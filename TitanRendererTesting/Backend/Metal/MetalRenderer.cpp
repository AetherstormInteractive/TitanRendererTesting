#include "MetalRenderer.h"

int MetalRenderer::Initialize(nlohmann::json configFile, bool is_fullscreen)
{
	window = SDL_CreateWindow("Metal Renderer", SDL_WINDOWPOS_CENTERED, 50, configFile["Display"]["Width"], configFile["Display"]["Height"], SDL_WINDOW_METAL | SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "ERROR: No Metal API Found!" << std::endl;
		return -1;
	}
	else
	{
		std::cout << "Metal Initialization" << std::endl;
	}

	return 0;
}

void MetalRenderer::Update(nlohmann::json configFile, bool is_fullscreen)
{
	SDL_SetWindowFullscreen(window, is_fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
}

void MetalRenderer::Shutdown()
{

}
