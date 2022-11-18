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
	virtual int Setup(SDL_Window* win, nlohmann::json configFile, bool is_fullscreen) = 0;
	virtual void Run(nlohmann::json configFile, bool is_fullscreen) = 0;
	virtual void Shutdown() = 0;
};
#endif