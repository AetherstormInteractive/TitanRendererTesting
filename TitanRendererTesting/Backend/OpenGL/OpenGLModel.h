#ifndef MODEL_H
#define MODEL_H

#include <glad/glad.h> 

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "OpenGLMesh.h"
#include "OpenGLShader.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

namespace Renderer
{
	namespace Backend
	{
		namespace OpenGL
		{
            
			class OpenGLModel
			{
            public:
                unsigned int TextureFromFile(const char* path, const std::string& directory, bool gamma = false);
                OpenGLModel(char* path)
                {
                    loadModel(path);
                }
                void Draw(Shader& shader);
            private:
                // model data
                std::vector<OpenGLMesh> meshes;
                std::string directory;

                void loadModel(std::string path);
                void processNode(aiNode* node, const aiScene* scene);
                OpenGLMesh processMesh(aiMesh* mesh, const aiScene* scene);
                std::vector<OpenGLTexture> loadMaterialTextures(aiMaterial* mat, aiTextureType type,
                    std::string typeName);
			};
		}
	}
}
#endif