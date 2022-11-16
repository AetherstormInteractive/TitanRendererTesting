#ifndef D3D11_RENDERER_H
#define D3D11_RENDERER_H

#include <cstdio>
#include <iostream>

#include <GLFW/glfw3.h>
#include <nlohmann/json.hpp>

#include "../../Renderer.h"

class D3D11Renderer : public Renderer
{
public:
	int Setup(GLFWwindow* win, nlohmann::json configFile, bool is_fullscreen);
	void Run(nlohmann::json configFile, bool is_fullscreen);
};
#endif