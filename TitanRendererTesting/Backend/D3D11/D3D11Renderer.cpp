#include "D3D11Renderer.h"

int D3D11Renderer::Initialize(nlohmann::json configFile, bool is_fullscreen)
{
	window = SDL_CreateWindow("DirectX11 Renderer", SDL_WINDOWPOS_CENTERED, 50, configFile["Display"]["Width"], configFile["Display"]["Height"], SDL_WINDOW_SHOWN);

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

void D3D11Renderer::Update(nlohmann::json configFile, bool is_fullscreen)
{
	SDL_SetWindowFullscreen(window, is_fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
}

void D3D11Renderer::Shutdown()
{

}