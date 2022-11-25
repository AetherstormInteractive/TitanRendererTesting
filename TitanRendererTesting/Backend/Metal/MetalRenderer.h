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
	int Initialize(nlohmann::json configFile, bool is_fullscreen);
	void Update(nlohmann::json configFile, bool is_fullscreen);
	void Shutdown();
};
#endif