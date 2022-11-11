#include "OpenGLRenderer.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int OpenGLRenderer::Setup(GLFWwindow* win, nlohmann::json configFile, bool is_fullscreen)
{
	glfwMakeContextCurrent(win);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
    return 0;
}

void OpenGLRenderer::Run(nlohmann::json configFile, bool is_fullscreen)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
