#include <cstdio>

#include <bx/math.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>
#include <glm/glm.hpp>

#include <nlohmann/json.hpp>

#include "BGFXModel.h"

namespace Renderer
{
	class BGFXRenderer
	{
	public:
		int Setup(GLFWwindow* win, nlohmann::json configFile, bool is_fullscreen);
		void Run(nlohmann::json configFile, bool is_fullscreen);

	private:
		std::vector<Backend::BGFX::BGFXModel> models;
	};
}
