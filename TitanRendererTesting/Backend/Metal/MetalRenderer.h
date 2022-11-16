#ifndef METAL_RENDERER_H
#define METAL_RENDERER_H

#include <cstdio>
#include <iostream>

#include <GLFW/glfw3.h>
#include <nlohmann/json.hpp>

#include "../../Renderer.h"

class MetalRenderer : public Renderer
{
public:
	int Setup(GLFWwindow* win, nlohmann::json configFile, bool is_fullscreen);
	void Run(nlohmann::json configFile, bool is_fullscreen);
};
#endif