// TitanVulkanTesting.cpp : Defines the entry point for the application.
//

#include "Scene.h"

using json = nlohmann::json;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

	int Scene::CreateWindow()
	{
		glfwInit();
		GLFWwindow* win;

		std::ifstream i("config.json");
		json j;
		i >> j;
		
		if (j["Display"]["Backend"] == "OpenGL")
		{
			USE_OPENGL = true;
		}

		if (j["Display"]["WindowMode"] == 1)
		{
			win = glfwCreateWindow(j["Display"]["FullscreenWidth"], j["Display"]["FullscreenHeight"], "Title", glfwGetPrimaryMonitor(), NULL);
		}
		else
		{
			win = glfwCreateWindow(j["Display"]["WindowedWidth"], j["Display"]["WindowedHeight"], "Title", NULL, NULL);
		}

		if (USE_OPENGL)
		{
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			glfwMakeContextCurrent(win);

			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				std::cout << "Failed to initialize GLAD" << std::endl;
				return -1;
			}
			glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
		}
		else
		{
			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		}

		glfwWindowHint(GLFW_REFRESH_RATE, j["Display"]["RefreshRate"]);

		if (win == nullptr)
		{
			return -1;
		}

		while (!glfwWindowShouldClose(win))
		{
			if (USE_OPENGL)
			{
				glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT);
			}

			glfwPollEvents();
			glfwSwapBuffers(win);
		}
		glfwTerminate();
		return 0;
	}
