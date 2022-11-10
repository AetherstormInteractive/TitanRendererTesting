#include "BGFXModel.h"

namespace Renderer
{
    namespace Backend
    {
        namespace BGFX
        {
            void BGFXModel::Draw()
            {
                for (unsigned int i = 0; i < meshes.size(); i++)
                    meshes[i].Draw();
            }

            void BGFXModel::loadModel(std::string path)
            {
                Assimp::Importer import;
                const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

                if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
                {
                    std::cout << "ERROR::ASSIMP::" << import.GetErrorString() << std::endl;
                    return;
                }
                directory = path.substr(0, path.find_last_of('/'));

                processNode(scene->mRootNode, scene);
            }

            void BGFXModel::processNode(aiNode* node, const aiScene* scene)
            {
                // process all the node's meshes (if any)
                for (unsigned int i = 0; i < node->mNumMeshes; i++)
                {
                    aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
                    meshes.push_back(processMesh(mesh, scene));
                }
                // then do the same for each of its children
                for (unsigned int i = 0; i < node->mNumChildren; i++)
                {
                    processNode(node->mChildren[i], scene);
                }
            }

            BGFXMesh BGFXModel::processMesh(aiMesh* mesh, const aiScene* scene)
            {
                std::vector<BGFXVertex> vertices;
                std::vector<unsigned int> indices;
                std::vector<BGFXTexture> textures;
                std::vector<BGFXTexture> textures_loaded;

                for (unsigned int i = 0; i < mesh->mNumVertices; i++)
                {
                    BGFXVertex vertex;
                    // process vertex positions, normals and texture coordinates
                    glm::vec3 vector;
                    vector.x = mesh->mVertices[i].x;
                    vector.y = mesh->mVertices[i].y;
                    vector.z = mesh->mVertices[i].z;
                    vertex.x = vector.x;
                    vertex.y = vector.y;
                    vertex.z = vector.z;

                    glm::vec3 normalVector;
                    normalVector.x = mesh->mNormals[i].x;
                    normalVector.y = mesh->mNormals[i].y;
                    normalVector.z = mesh->mNormals[i].z;
                    vertex.normal_x = normalVector.x;
                    vertex.normal_y = normalVector.y;
                    vertex.normal_z = normalVector.z;

                    if (mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
                    {
                        glm::vec2 textureVector;
                        textureVector.x = mesh->mTextureCoords[0][i].x;
                        textureVector.y = mesh->mTextureCoords[0][i].y;
                        vertex.tex_coords_x = textureVector.x;
                        vertex.tex_coords_y = textureVector.y;
                    }

                    vertices.push_back(vertex);
                }
                // process indices
                for (unsigned int i = 0; i < mesh->mNumFaces; i++)
                {
                    aiFace face = mesh->mFaces[i];
                    for (unsigned int j = 0; j < face.mNumIndices; j++)
                        indices.push_back(face.mIndices[j]);
                }

                // TODO
                // process material
                //if (mesh->mMaterialIndex >= 0)
                //{
                //    
                //}

                return BGFXMesh(vertices, indices, textures);
            }

            // TODO
            //std::vector<Texture> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName)
            //{
            //    std::vector<Texture> textures;
            //    for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
            //    {
            //        aiString str;
            //        mat->GetTexture(type, i, &str);
            //        Texture texture;
            //        texture.id = TextureFromFile(str.C_Str(), directory);
            //        texture.type = typeName;
            //        texture.path = str;
            //        textures.push_back(texture);
            //    }
            //    return textures;
            //}
        }
    }
}