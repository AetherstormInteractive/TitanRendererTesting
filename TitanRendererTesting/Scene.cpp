// TitanVulkanTesting.cpp : Defines the entry point for the application.
//

#include "Scene.h"


void Scene::SceneUpdate()
{

	bgfx::ProgramHandle shader;
	auto view = registry.view<Model>();

	while (!glfwWindowShouldClose(window))
	{
		for (auto entity : view)
		{
			auto& model = view.get<Model>(entity);
			renderer->Draw(model, shader);
		}
		renderer->Run(j);
		if (glfwGetKey(window, GLFW_KEY_F1))
		{
			break;
		}
		glfwPollEvents();
	}
}

	int Scene::SceneStart()
	{
		glfwInit();

		std::ifstream i("config.ini");

		i >> j;

		if (j["Display"]["WindowMode"] == 1)
		{
			window = glfwCreateWindow(j["Display"]["FullscreenWidth"], j["Display"]["FullscreenHeight"], "TitanRendererTesting", glfwGetPrimaryMonitor(), NULL);
		}
		else
		{
			window = glfwCreateWindow(j["Display"]["WindowedWidth"], j["Display"]["WindowedHeight"], "TitanRendererTesting", NULL, NULL);
		}
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		glfwWindowHint(GLFW_REFRESH_RATE, j["Display"]["RefreshRate"]);

		if (window == nullptr)
		{
			return -1;
		}
		
		renderer->Setup(window, j);

		SceneUpdate();
		return 0;
	}

	int Scene::SceneEnd()
	{
		glfwTerminate();
		return 0;
	}

	void Scene::CreateEntity(entt::entity entity)
	{
		entity = registry.create();
	}

	void Scene::DeleteEntity(entt::entity entity)
	{
		registry.destroy(entity);
	}
