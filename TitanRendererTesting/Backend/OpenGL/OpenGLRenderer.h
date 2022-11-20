#ifndef OPENGL_RENDERER_H
#define OPENGL_RENDERER_H

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
	int Initialize(nlohmann::json configFile, bool is_fullscreen);
	void Update(nlohmann::json configFile, bool is_fullscreen);
	void Shutdown();
private:
float vertices[9] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};

	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\0";

	unsigned int vertexShader;
	unsigned int fragmentShader;

	unsigned int shaderProgram;

	unsigned int VBO;
	unsigned int VAO;

	SDL_GLContext gContext;
};
#endif