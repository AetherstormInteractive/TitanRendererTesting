#include "OpenGLRenderer.h"

int OpenGLRenderer::Setup(GLFWwindow* win, nlohmann::json configFile)
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    stbi_set_flip_vertically_on_load(true);
    camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
	shader = Shader("shaders/vs_mesh.vs", "shaders/fs_mesh.fs");
	model = &Renderer::Backend::OpenGL::OpenGLModel("resources/objects/backpack/backpack.obj");

    return 0;
}

void OpenGLRenderer::Run(nlohmann::json configFile)
{
	glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader.use();

    glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)configFile["Display"]["WindowedWidth"] / (float)configFile["Display"]["WindowedHeight"], 0.1f, 100.0f);
    glm::mat4 view = camera.GetViewMatrix();
    shader.setMat4("projection", projection);
    shader.setMat4("view", view);

    // render the loaded model
    glm::mat4 modelTran = glm::mat4(1.0f);
    modelTran = glm::translate(modelTran, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
    modelTran = glm::scale(modelTran, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
    shader.setMat4("model", modelTran);
    //model->Draw(shader);
	
}
