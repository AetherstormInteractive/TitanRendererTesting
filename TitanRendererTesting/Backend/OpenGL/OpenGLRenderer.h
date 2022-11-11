#include <cstdio>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "OpenGLCamera.h"
#include "OpenGLShader.h"
#include "OpenGLModel.h"


#include <nlohmann/json.hpp>

class OpenGLRenderer
{

public:
	int Setup(GLFWwindow* win, nlohmann::json configFile, bool is_fullscreen);
	void Run(nlohmann::json configFile, bool is_fullscreen);
};