#include "D3D11Renderer.h"

int D3D11Renderer::Initialize(nlohmann::json configFile, int windowMode)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}

	window = SDL_CreateWindow("DirectX11 Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, configFile["Display"]["Width"], configFile["Display"]["Height"], SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "ERROR: No DirectX11 API Found!" << std::endl;
		return -1;
	}
	else
	{
		std::cout << "DirectX11 Initialization" << std::endl;
	}

	return 0;
}

void D3D11Renderer::Update(nlohmann::json configFile, int windowMode)
{
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

void D3D11Renderer::Shutdown()
{
	SDL_Quit();
}