#ifndef D3D12_RENDERER_H
#define D3D12_RENDERER_H

#include <cstdio>
#include <iostream>

#include <SDL3/SDL.h>
#undef main

#include <nlohmann/json.hpp>

#include "../../Renderer.h"

class D3D12Renderer : public Renderer
{
public:
	int Initialize(nlohmann::json configFile, int windowMode);
	void Update(float deltaTime, int windowMode);
	void Draw();
	void Shutdown();
};
#endif