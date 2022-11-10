#include <iostream>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <bgfx/bgfx.h>

#include <glm/glm.hpp>

#include "BGFXMesh.h"

namespace Renderer
{
    namespace Backend
    {
        namespace BGFX
        {
            class BGFXModel
            {
            public:
                BGFXModel(char* path)
                {
                    loadModel(path);
                }
                void Draw();
            private:
                // model data
                std::vector<BGFXTexture> textures_loaded;
                std::vector<BGFXMesh> meshes;
                std::string directory;

                void loadModel(std::string path);
                void processNode(aiNode* node, const aiScene* scene);
                BGFXMesh processMesh(aiMesh* mesh, const aiScene* scene);
                std::vector<BGFXTexture> loadMaterialTextures(aiMaterial* mat, aiTextureType type,
                    std::string typeName);
            };
        }
    }
}