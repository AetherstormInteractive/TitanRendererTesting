#ifndef MESH_H
#define MESH_H

#include <glad/glad.h> // holds all OpenGL type declarations

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "OpenGLShader.h"

#include <string>
#include <vector>

namespace Renderer
{
	namespace Backend
	{
		namespace OpenGL
		{
			struct OpenGLVertex
			{
				glm::vec3 Position;
				glm::vec3 Normal;
				glm::vec2 TexCoords;
			};

			struct OpenGLTexture
			{
				unsigned int id;
				std::string type;
				std::string path;
			};


			class OpenGLMesh
			{
			public:
				// mesh data
				std::vector<OpenGLVertex>       vertices;
				std::vector<unsigned int> indices;
				std::vector<OpenGLTexture>      textures;

				OpenGLMesh(std::vector<OpenGLVertex> vertices, std::vector<unsigned int> indices, std::vector<OpenGLTexture> textures);
				void Draw(Shader& shader);
			private:
				//  render data
				unsigned int VAO, VBO, EBO;

				void setupMesh();
			};
		}
	}
}
#endif