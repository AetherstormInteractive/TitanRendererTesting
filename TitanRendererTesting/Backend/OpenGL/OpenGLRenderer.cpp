#include "OpenGLRenderer.h"

void OpenGLRenderer::loadShader(const char* vertexpath, const char* fragmentpath)
{
	std::string vertexline, vertextext;
	std::ifstream vertexin(vertexpath);
	while (std::getline(vertexin, vertexline))
	{
		vertextext += vertexline + "\n";
	}
	const char* vertexdata = vertextext.c_str();
	vertexin.close();

	std::string fragmentline, fragmenttext;
	std::ifstream fragmentin(fragmentpath);
	while (std::getline(fragmentin, fragmentline))
	{
		fragmenttext += fragmentline + "\n";
	}
	const char* fragmentdata = fragmenttext.c_str();
	fragmentin.close();

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, &vertexdata, NULL);
	glCompileShader(vertexShader);

	glShaderSource(fragmentShader, 1, &fragmentdata, NULL);
	glCompileShader(fragmentShader);


	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
}

int OpenGLRenderer::Initialize(nlohmann::json configFile, int windowMode)
{
	//init sdl2
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}

	//sdl load openGL library
	SDL_GL_LoadLibrary(NULL);
	// Request an OpenGL 4.5 context (should be core)
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
	// Also request a depth buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	//create window at center screen with openGL context
	window = SDL_CreateWindow("OpenGL Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, configFile["Display"]["Width"], configFile["Display"]["Height"], SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	//window nullcheck
	if (window == NULL)
	{
		std::cout << "ERROR: No OpenGL API Found!" << std::endl;
		return -1;
	}
	else
	{
		std::cout << "OpenGL Initialization" << std::endl;
	}

	//set opengl context using sdl2
	gContext = SDL_GL_CreateContext(window);
	//load opengl extensions using glad
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		std::cout << "GLAD Initialization Failed!" << std::endl;
		return -1;
	}

	//set opengl viewport
	glViewport(0, 0, SDL_GetWindowSurface(window)->w, SDL_GetWindowSurface(window)->h);

	loadShader("resources/shaders/opengl/shader.vert", "resources/shaders/opengl/shader.frag");

	//generate vertexBuffer and load vertices array
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//generate vertex arrays
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	//set vertex attributes and enable vertexArray
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
    return 0;
}

void OpenGLRenderer::Update(float deltaTime, int windowMode)
{
	//update gl viewport
	glViewport(0, 0, SDL_GetWindowSurface(window)->w, SDL_GetWindowSurface(window)->h);

	//set window mode
	switch (windowMode) {
	case 0:
		SDL_SetWindowFullscreen(window, 0);
		break;
	case 1:
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
		break;
	case 2:
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
		break;
	}

	//swap sdl2 buffers for opengl
	SDL_GL_SwapWindow(window);
}

void OpenGLRenderer::Draw()
{
	//create background color
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//set shader program, vertex array, and draw all
	glUseProgram(shaderProgram);
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void OpenGLRenderer::Shutdown()
{
	//delete opengl shaders
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	//clear vertex array and buffers
	glDeleteVertexArrays(1, &vertexArray);
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteProgram(shaderProgram);

	//destroy sdl2
	SDL_DestroyWindow(window);
	SDL_Quit();
}