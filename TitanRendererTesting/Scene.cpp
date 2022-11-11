#include "Scene.h"

#define USE_OPENGL

bool is_fullscreen;
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	std::ifstream i("config.ini");
	json configFile;
	i >> configFile;
	if (key == GLFW_KEY_F11 && action == GLFW_PRESS)
	{
		is_fullscreen = !is_fullscreen;
		glfwSetWindowMonitor(window, is_fullscreen ? glfwGetPrimaryMonitor() : NULL, 500, 300,
			is_fullscreen ? configFile["Display"]["FullscreenWidth"] : configFile["Display"]["WindowedWidth"], 
			is_fullscreen ? configFile["Display"]["FullscreenHeight"] : configFile["Display"]["WindowedHeight"], 
			configFile["Display"]["RefreshRate"]);
	}
	configFile["Display"]["isFullscreen"] = is_fullscreen;
	if (key == GLFW_KEY_F1 && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

int Scene::SceneStart()
{
	std::ifstream i("config.ini");
	i >> configFile;
	is_fullscreen = configFile["Display"]["isFullscreen"];

	glfwInit();

#ifdef USE_OPENGL
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#else
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
#endif

	window = glfwCreateWindow(
		is_fullscreen ? configFile["Display"]["FullscreenWidth"] : configFile["Display"]["WindowedWidth"],
		is_fullscreen ? configFile["Display"]["FullscreenHeight"] : configFile["Display"]["WindowedHeight"],
		"TitanRendererTesting", 
		is_fullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);

	glfwWindowHint(GLFW_REFRESH_RATE, configFile["Display"]["RefreshRate"]);

	if (window == nullptr)
	{
		return -1;
	}

	glfwSetKeyCallback(window, key_callback);

	renderer.Setup(window, configFile, is_fullscreen);

	SceneUpdate();
	return 0;
}

void Scene::SceneUpdate()
{
	while (!glfwWindowShouldClose(window))
	{
		renderer.Run(configFile, is_fullscreen);

		glfwSwapBuffers(window);
		glfwPollEvents();
	} // game loop
}

int Scene::SceneEnd()
{
	for (int i = 0; i <= sizeof(entities); i++)
	{
		if (entities.empty())
		{
			break;
		}
		registry.destroy(entities[i]);
	}
	//bgfx::shutdown();
	glfwTerminate();
	return 0;
}

void Scene::CreateEntity(entt::entity entity)
{
	entity = registry.create(); // add entity to scene registry
	entities.push_back(entity); //add entity for universal use
}

void Scene::DeleteEntity(entt::entity entity)
{
	registry.destroy(entity); // remove entity from scene registry
	entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end()); //delete entity with iterator
}


