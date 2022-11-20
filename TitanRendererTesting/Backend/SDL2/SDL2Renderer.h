#ifndef SDL2_RENDERER_H
#define SDL2_RENDERER_H

#include <SDL.h>
#undef main

#include <nlohmann/json.hpp>

#include "../../Renderer.h"

class SDL2Renderer : public Renderer
{
public:
	int Initialize(nlohmann::json configFile, bool is_fullscreen);
	void Update(nlohmann::json configFile, bool is_fullscreen);
	void Shutdown();
};
#endif