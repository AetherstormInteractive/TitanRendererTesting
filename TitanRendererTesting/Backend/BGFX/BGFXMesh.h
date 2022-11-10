#include <vector>
#include <string>
#include <iostream>
#include <cstdio>

#include <bgfx/bgfx.h>

namespace Renderer
{
	namespace Backend
	{
		namespace BGFX
		{
			struct BGFXVertex
			{
				float x;
				float y;
				float z;
				float normal_x;
				float normal_y;
				float normal_z;
				//float tangent_x;
				//float tangent_y;
				//float tangent_z;
				//float tangent_w;
				float tex_coords_x;
				float tex_coords_y;
			};

			struct BGFXTexture
			{
				unsigned int id;
				std::string type;
				std::string path;
			};

			class BGFXMesh
			{
			public:
				std::vector<BGFXVertex>       vertices;
				std::vector<unsigned int> indices;
				std::vector<BGFXTexture>      textures;

				BGFXMesh(std::vector<BGFXVertex> vertices, std::vector<unsigned int> indices, std::vector<BGFXTexture> textures);
				void Draw();
			private:
				//  render data
				bgfx::ShaderHandle loadShader(const char* FILENAME);
				bgfx::VertexBufferHandle vertexBufferHandle;
				bgfx::IndexBufferHandle indexBufferHandle;
				bgfx::ProgramHandle program;

				void setupMesh();
			};
		}
	}
}