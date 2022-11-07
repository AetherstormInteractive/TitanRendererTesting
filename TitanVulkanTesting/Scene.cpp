// TitanVulkanTesting.cpp : Defines the entry point for the application.
//

#include "Scene.h"

using json = nlohmann::json;

void Scene::Update()
{
}

	int Scene::SceneCreateWindow()
	{
		glfwInit();
		GLFWwindow* window;

		std::ifstream i("config.json");
		json j;
		i >> j;

		if (j["Display"]["WindowMode"] == 1)
		{
			window = glfwCreateWindow(j["Display"]["FullscreenWidth"], j["Display"]["FullscreenHeight"], "Title", glfwGetPrimaryMonitor(), NULL);
		}
		else
		{
			window = glfwCreateWindow(j["Display"]["WindowedWidth"], j["Display"]["WindowedHeight"], "Title", NULL, NULL);
		}
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		glfwWindowHint(GLFW_REFRESH_RATE, j["Display"]["RefreshRate"]);

		if (window == nullptr)
		{
			return -1;
		}
		
		renderer->Setup(window, j);

	

		while (!glfwWindowShouldClose(window))
		{
			renderer->Run(j);
			glfwPollEvents();
		}
		glfwTerminate();
		return 0;
	}
