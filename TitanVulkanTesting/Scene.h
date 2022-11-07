// TitanVulkanTesting.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <fstream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"
#include "nlohmann/json.hpp"

class Scene
{
public:
	int CreateWindow();
private:
	bool USE_OPENGL;
};
	
// TODO: Reference additional headers your program requires here.
