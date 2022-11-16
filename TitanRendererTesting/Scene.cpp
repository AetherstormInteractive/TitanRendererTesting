#include "Scene.h"

bool is_fullscreen;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
#if defined(USE_OPENGL)
	glViewport(0, 0, width, height);
#elif defined(USE_D3D11)

#elif defined(USE_D3D12)

#elif defined(USE_VULKAN)

#elif defined(USE_METAL)

#endif
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	std::ifstream i("config.ini");
	json configFile;
	i >> configFile;
	if (key == GLFW_KEY_F11 && action == GLFW_PRESS)
	{
		is_fullscreen = !is_fullscreen;
		glfwSetWindowMonitor(window, is_fullscreen ? glfwGetPrimaryMonitor() : NULL, 500, 300,
			configFile["Display"]["Width"],
			configFile["Display"]["Height"],
			configFile["Display"]["RefreshRate"]);

		std::ifstream in("config.ini");
		json infile = json::parse(in);

		infile["Display"]["isFullscreen"] = is_fullscreen;

		std::ofstream out("config.ini");
		out << std::setw(4) << infile << std::endl;

		in.close();
		out.close();
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
        switch (configFile["Display"]["Backend"])
        {
                case "OpenGL":
#define USE_OPENGL
                        break;
                case "Vulkan":
#define USE_VULKAN
                        break;
                case "DirectX11":
#define USE_D3D11
                        break;
                case "DirectX12":
#define USE_D3D12
                        break;
                case "Metal":
#define USE_METAL
                        break;
        }   
	glfwInit();

#ifdef USE_OPENGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#else
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
#endif

	window = glfwCreateWindow(
		configFile["Display"]["Width"],
		configFile["Display"]["Height"],
		"TitanRendererTesting", 
		is_fullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);

	glfwWindowHint(GLFW_REFRESH_RATE, configFile["Display"]["RefreshRate"]);

	if (window == nullptr)
	{
		return -1;
	}
	renderer.Setup(window, configFile, is_fullscreen);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, key_callback);

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


