#include "OpenGLRenderer.h"


int OpenGLRenderer::Setup(SDL_Window* win, nlohmann::json configFile, bool is_fullscreen)
{
	std::cout << "OpenGL Initialization" << std::endl;
	gContext = SDL_GL_CreateContext(win);
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, configFile["Display"]["Width"], configFile["Display"]["Height"]);
    return 0;
}

void OpenGLRenderer::Run(nlohmann::json configFile, bool is_fullscreen)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}