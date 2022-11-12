#ifndef D3D11_RENDERER_H
#define D3D11_RENDERER_H

#include <cstdio>
#include <iostream>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <nlohmann/json.hpp>

namespace Renderer
{
	class D3D11Renderer
	{
	public:
		int Setup(GLFWwindow* win, nlohmann::json configFile, bool is_fullscreen);
		void Run(nlohmann::json configFile, bool is_fullscreen);
	};
}
#endif