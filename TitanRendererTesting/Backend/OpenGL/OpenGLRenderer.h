#include <cstdio>
#include <iostream>

#include <glad/glad.h>
#include <SDL.h>
#undef main
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <nlohmann/json.hpp>

#include "../../Renderer.h"

class OpenGLRenderer : public Renderer
	{
	public:
		int Setup(SDL_Window* win, nlohmann::json configFile, bool is_fullscreen);
		void Run(nlohmann::json configFile, bool is_fullscreen);
	};