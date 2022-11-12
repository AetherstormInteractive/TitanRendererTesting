#include <cstdio>
#include <iostream>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <nlohmann/json.hpp>

namespace Renderer
{
	class VulkanRenderer
	{
	public:
		int Setup(GLFWwindow* win, nlohmann::json configFile, bool is_fullscreen);
		void Run(nlohmann::json configFile, bool is_fullscreen);
	};
}