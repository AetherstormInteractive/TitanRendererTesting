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
	virtual int Initialize(nlohmann::json configFile, int windowMode) = 0;
	virtual void Update(float deltaTime, int windowMode) = 0;
	virtual void Draw() = 0;
	virtual void Shutdown() = 0;

	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
};
#endif