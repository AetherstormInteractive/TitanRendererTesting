#include "Scene.h"

SDL_Event e;
bool quit = false;

int Scene::SceneStart()
{
	std::ifstream i("config.ini");
	i >> configFile;
	is_fullscreen = configFile["Display"]["isFullscreen"];
	api->Initialize(configFile, is_fullscreen);

	return 0;
}

void Scene::SceneUpdate()
{
	while (!quit) 
	{
		api->Update(configFile, is_fullscreen);

		while (SDL_PollEvent(&e)) 
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_F11:
					is_fullscreen = !is_fullscreen;
					break;
				case SDLK_F5:
					api->Shutdown();
					api = nullptr;
					api = vulkanrenderer;
					api->Initialize(configFile, is_fullscreen);
					break;
				case SDLK_F1:
					quit = true;
					break;
				}
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

	//Quit SDL subsystem

	api->Shutdown();

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


