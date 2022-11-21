#include "SDL2Renderer.h"


int SDL2Renderer::Initialize(nlohmann::json configFile, bool is_fullscreen)
{
	window = SDL_CreateWindow("SDL2 Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, configFile["Display"]["Width"], configFile["Display"]["Height"], SDL_WINDOW_SHOWN);
	std::cout << "SDL2 Initialization" << std::endl;
	return 0;
}

void SDL2Renderer::Update(nlohmann::json configFile, bool is_fullscreen)
{
	SDL_SetWindowFullscreen(window, is_fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
}

void SDL2Renderer::Shutdown()
{

}
