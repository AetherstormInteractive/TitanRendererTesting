#include "MetalRenderer.h"


int MetalRenderer::Initialize(nlohmann::json configFile, bool is_fullscreen)
{
	window = SDL_CreateWindow("Metal Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, configFile["Display"]["Width"], configFile["Display"]["Height"], SDL_WINDOW_METAL | SDL_WINDOW_SHOWN);
	std::cout << "Metal Initialization" << std::endl;
	return 0;
}

void MetalRenderer::Update(nlohmann::json configFile, bool is_fullscreen)
{
	SDL_SetWindowFullscreen(window, is_fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
}

void MetalRenderer::Shutdown()
{

}
