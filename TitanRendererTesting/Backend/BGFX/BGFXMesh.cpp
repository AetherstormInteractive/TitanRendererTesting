#include "BGFXMesh.h"

namespace Renderer
{
    namespace Backend
    {
        namespace BGFX
        {
            BGFXMesh::BGFXMesh(std::vector<BGFXVertex> vertices, std::vector<unsigned int> indices, std::vector<BGFXTexture> textures)
            {
                this->vertices = vertices;
                this->indices = indices;
                this->textures = textures; //storing vertices from Model.h within class

                setupMesh();
            }

            void BGFXMesh::Draw()
            {

                //TODO ^^^^ material handling for drawing later

                bgfx::setVertexBuffer(0, vertexBufferHandle);
                bgfx::setIndexBuffer(indexBufferHandle);
                bgfx::submit(0, program); // add buffer to bgfx draw calls and add shader program to submit
            }

            bgfx::ShaderHandle BGFXMesh::loadShader(const char* FILENAME)
            {
                const char* shaderPath = "???";

                switch (bgfx::getRendererType())
                {
                case bgfx::RendererType::Noop:
                case bgfx::RendererType::Direct3D9:  shaderPath = "shaders/dx9/";   break;
                case bgfx::RendererType::Direct3D11:
                case bgfx::RendererType::Direct3D12: shaderPath = "shaders/dx11/";  break;
                case bgfx::RendererType::OpenGL:     shaderPath = "shaders/glsl/";  break;
                case bgfx::RendererType::Vulkan:     shaderPath = "shaders/spirv/"; break;
                } // choose renderer

                size_t shaderLen = strlen(shaderPath);
                size_t fileLen = strlen(FILENAME);
                char* filePath = (char*)calloc(1, shaderLen + fileLen + 1);
                memcpy(filePath, shaderPath, shaderLen);
                memcpy(&filePath[shaderLen], FILENAME, fileLen);

                FILE* file = fopen(filePath, "rb");
                fseek(file, 0, SEEK_END);
                long fileSize = ftell(file);
                fseek(file, 0, SEEK_SET);

                const bgfx::Memory* mem = bgfx::alloc(fileSize + 1);
                fread(mem->data, 1, fileSize, file);
                mem->data[mem->size - 1] = '\0';
                fclose(file);

                return bgfx::createShader(mem); // load Shader
            }

            void BGFXMesh::setupMesh()
            {
                bgfx::VertexLayout vertexLayout;
                vertexLayout
                    .begin()
                    .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
                    .add(bgfx::Attrib::Normal, 3, bgfx::AttribType::Uint8, true, true)
                    //.add(bgfx::Attrib::Tangent, 4, bgfx::AttribType::Uint8, true, true)
                    .add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Int16, true, true)
                    .end(); // define shape of Vertex for bgfx

                vertexBufferHandle = bgfx::createVertexBuffer(bgfx::makeRef(vertices.data(), sizeof(vertices)), vertexLayout);
                indexBufferHandle = bgfx::createIndexBuffer(bgfx::makeRef(indices.data(), sizeof(indices))); // create buffers full of vertices and indices after pulling from Model.h

                bgfx::ShaderHandle vertexShader = loadShader("vs_mesh.bin");
                bgfx::ShaderHandle fragmentShader = loadShader("fs_mesh.bin");
                program = bgfx::createProgram(vertexShader, fragmentShader, true); // load shaders and create a program to be submitted to bgfx

            }
        }
    }
}