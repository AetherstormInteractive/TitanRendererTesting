#include "D3D12Renderer.h"

int D3D12Renderer::Initialize(nlohmann::json configFile, bool is_fullscreen)
{
	window = SDL_CreateWindow("D3D12 Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, configFile["Display"]["Width"], configFile["Display"]["Height"], SDL_WINDOW_SHOWN);
	std::cout << "D3D12 Initialization" << std::endl;
	return 0;
}

void D3D12Renderer::Update(nlohmann::json configFile, bool is_fullscreen)
{

}

void D3D12Renderer::Shutdown()
{

}