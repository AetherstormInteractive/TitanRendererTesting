#include "Scene.h"

bool is_fullscreen;

//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
//{
//	std::ifstream i("config.ini");
//	json configFile;
//	i >> configFile;
//	if (key == GLFW_KEY_F11 && action == GLFW_PRESS)
//	{
//		is_fullscreen = !is_fullscreen;
//		glfwSetWindowMonitor(window, is_fullscreen ? glfwGetPrimaryMonitor() : NULL, 500, 300,
//			configFile["Display"]["Width"],
//			configFile["Display"]["Height"],
//			configFile["Display"]["RefreshRate"]);
//
//		std::ifstream in("config.ini");
//		json infile = json::parse(in);
//
//		infile["Display"]["isFullscreen"] = is_fullscreen;
//
//		std::ofstream out("config.ini");
//		out << std::setw(4) << infile << std::endl;
//
//		in.close();
//		out.close();
//	}
//	configFile["Display"]["isFullscreen"] = is_fullscreen;
//	if (key == GLFW_KEY_F1 && action == GLFW_PRESS)
//	{
//	        glfwSetWindowShouldClose(window, true);
//	}
//}

SDL_Event e;
bool quit = false;

int Scene::SceneStart()
{

	std::ifstream i("config.ini");
	i >> configFile;
	is_fullscreen = configFile["Display"]["isFullscreen"];

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		if (api == openglrenderer)
		{
			window = SDL_CreateWindow("Titan Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, configFile["Display"]["Width"], configFile["Display"]["Height"], SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		}
		else if (api == vulkanrenderer)
		{
			window = SDL_CreateWindow("Titan Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, configFile["Display"]["Width"], configFile["Display"]["Height"], SDL_WINDOW_VULKAN | SDL_WINDOW_SHOWN);
		}
		
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGBA(screenSurface->format, 51, 77, 77, 255));

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Hack to get window to stay up

		}
	}

	api->Setup(window, configFile, is_fullscreen);

	SceneUpdate();
	return 0;
}

void Scene::SceneUpdate()
{
	while (quit == false) 
	{ 
		while (SDL_PollEvent(&e)) 
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}
}

int Scene::SceneEnd()
{
	for (int i = 0; i <= sizeof(entities); i++)
	{
		if (!entities.empty())
		{
			registry.destroy(entities[i]);
		}
	}
	SDL_DestroyWindow(window);
	//Quit SDL subsystems
	SDL_Quit();

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


