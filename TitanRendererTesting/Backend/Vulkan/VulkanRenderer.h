#include <GLFW/glfw3.h>

#include <nlohmann/json.hpp>

#include "../../Renderer.h"

class VulkanRenderer : public Renderer
{
public:
	int Setup(GLFWwindow* win, nlohmann::json configFile, bool is_fullscreen);
	void Run(nlohmann::json configFile, bool is_fullscreen);
};