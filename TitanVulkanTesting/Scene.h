// TitanVulkanTesting.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <fstream>

#include "BGFXRenderer.h"
#include "entt/entt.hpp"

class Scene
{
public:
	//entt::registry registry;
	BGFXRenderer* renderer = new BGFXRenderer();

	void Update();

	int SceneCreateWindow();

	void CreateEntity();

	void DeleteEntity();
};
	
// TODO: Reference additional headers your program requires here.
