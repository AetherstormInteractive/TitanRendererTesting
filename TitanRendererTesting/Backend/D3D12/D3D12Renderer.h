#ifndef D3D12_RENDERER_H
#define D3D12_RENDERER_H

#include <cstdio>
#include <iostream>

#include <SDL.h>
#undef main

#include <nlohmann/json.hpp>

#include "../../Renderer.h"

class D3D12Renderer : public Renderer
{
public:
	int Setup(SDL_Window* win, nlohmann::json configFile, bool is_fullscreen);
	void Run(nlohmann::json configFile, bool is_fullscreen);
	void Shutdown();
};
#endif