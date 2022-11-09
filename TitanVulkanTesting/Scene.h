// TitanVulkanTesting.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <fstream>
#include "entt/entt.hpp"
#include "BGFXRenderer.h"

using json = nlohmann::json;

class Scene
{
public:
	entt::registry registry;
	BGFXRenderer* renderer = new BGFXRenderer();
	json j;
	GLFWwindow* window;

	void SceneUpdate();

	int SceneStart();

	int SceneEnd();

	void CreateEntity(entt::entity entity);

	void DeleteEntity(entt::entity entity);
};
	
// TODO: Reference additional headers your program requires here.
