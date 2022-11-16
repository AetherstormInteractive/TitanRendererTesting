#ifndef RENDERER_H
#define RENDERER_H

#include <cstdio>
#include <iostream>
#include <GLFW/glfw3.h>
#include <nlohmann/json.hpp>

class Renderer
{
public:
	virtual int Setup(GLFWwindow* win, nlohmann::json configFile, bool is_fullscreen) = 0;
	virtual void Run(nlohmann::json configFile, bool is_fullscreen) = 0;
};
#endif