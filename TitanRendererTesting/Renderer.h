#ifndef RENDERER_H
#define RENDERER_H

#include <cstdio>
#include <iostream>
#include <SDL.h>
#undef main
#include <nlohmann/json.hpp>

class Renderer
{
public:
	virtual int Initialize(nlohmann::json configFile, bool is_fullscreen) = 0;
	virtual void Update(nlohmann::json configFile, bool is_fullscreen) = 0;
	virtual void Shutdown() = 0;

	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
};
#endif