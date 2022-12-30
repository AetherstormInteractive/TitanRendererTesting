#ifndef OPENGL_RENDERER_H
#define OPENGL_RENDERER_H

#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>

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
	int Initialize(nlohmann::json configFile, int windowMode);
	void loadShader(const char* vertexpath, const char* fragmentpath);
	void Update(float deltaTime, int windowMode);
	void Draw();
	void Shutdown();
private:
	float vertices[9] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
		};

	unsigned int vertexShader;
	unsigned int fragmentShader;

	unsigned int shaderProgram;

	unsigned int vertexBuffer;
	unsigned int vertexArray;

	SDL_GLContext gContext;
};
#endif