#ifndef METAL_RENDERER_H
#define METAL_RENDERER_H

#include <cstdio>
#include <iostream>

#include <SDL.h>
#undef main

#include <nlohmann/json.hpp>

#include "../../Renderer.h"

class MetalRenderer : public Renderer
{
public:
	int Initialize(nlohmann::json configFile, int windowMode);
	void Update(nlohmann::json configFile, int windowMode);
	void Shutdown();
};
#endif