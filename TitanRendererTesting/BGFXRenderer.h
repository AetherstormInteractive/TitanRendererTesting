
#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "GLFW/glfw3.h"
#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW/glfw3native.h"

#include "nlohmann/json.hpp"

struct Texture
{
	unsigned int id;
	std::string type;
};

class Mesh
{
public:
	void SetupMesh()
	{

	}

	void Draw(bgfx::ProgramHandle shader)
	{
		
	}
};

class Model
{
public:
	std::vector<Mesh> meshes;
	std::string directory;

	void Draw(bgfx::ProgramHandle shader)
	{
		for (unsigned int i = 0; i < meshes.size(); i++)
			meshes[i].Draw(shader);
	}

	void loadModel()
	{

	}

	void processNode()
	{

	}

	Mesh processMesh()
	{

	}

	std::vector<Texture> loadMaterialTextures()
	{

	}
};

class BGFXRenderer
{
	public:
	int Setup(GLFWwindow* win, nlohmann::json j)
	{
		bgfx::PlatformData platformData;
		bgfx::setPlatformData(platformData);

		uint16_t m_pciId = 0;

		bgfx::Init init;
		init.type = bgfx::RendererType::Count;
		init.vendorId = m_pciId;
		init.platformData.nwh = glfwGetWin32Window(win);
		init.platformData.ndt = glfwGetPrimaryMonitor();

		if (j["Display"]["WindowMode"] == 1)
		{
			init.resolution.width = j["Display"]["FullscreenWidth"];
			init.resolution.height = j["Display"]["FullscreenHeight"];
		}
		else
		{
			init.resolution.width = j["Display"]["WindowedWidth"];
			init.resolution.height = j["Display"]["WindowedHeight"];
		}

		init.resolution.reset = BGFX_RESET_VSYNC;
		bgfx::init(init);

		bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);

		return 0;
	}

	bgfx::ShaderHandle loadShader(const char* FILENAME)
	{
		const char* shaderPath = "???";

		switch (bgfx::getRendererType())
		{
		case bgfx::RendererType::Noop:
		case bgfx::RendererType::Direct3D9:  shaderPath = "shaders/dx9/";   break;
		case bgfx::RendererType::Direct3D11:
		case bgfx::RendererType::Direct3D12: shaderPath = "shaders/dx11/";  break;
		case bgfx::RendererType::Gnm:        shaderPath = "shaders/pssl/";  break;
		case bgfx::RendererType::Metal:      shaderPath = "shaders/metal/"; break;
		case bgfx::RendererType::OpenGL:     shaderPath = "shaders/glsl/";  break;
		case bgfx::RendererType::OpenGLES:   shaderPath = "shaders/essl/";  break;
		case bgfx::RendererType::Vulkan:     shaderPath = "shaders/spirv/"; break;
		}

		size_t shaderLen = strlen(shaderPath);
		size_t fileLen = strlen(FILENAME);
		char* filePath = (char*)malloc(shaderLen + fileLen);
		memcpy(filePath, shaderPath, shaderLen);
		memcpy(&filePath[shaderLen], FILENAME, fileLen);

		FILE* file = fopen(FILENAME, "rb");
		fseek(file, 0, SEEK_END);
		long fileSize = ftell(file);
		fseek(file, 0, SEEK_SET);

		const bgfx::Memory* mem = bgfx::alloc(fileSize + 1);
		fread(mem->data, 1, fileSize, file);
		mem->data[mem->size - 1] = '\0';
		fclose(file);

		return bgfx::createShader(mem);
	}

	void Run(nlohmann::json j)
	{
		if (j["Display"]["WindowMode"] == 1)
		{
			bgfx::setViewRect(0, 0, 0, j["Display"]["FullscreenWidth"], j["Display"]["FullscreenHeight"]);
		}
		else
		{
			bgfx::setViewRect(0, 0, 0, j["Display"]["WindowedWidth"], j["Display"]["WindowedHeight"]);
		}

		bgfx::touch(0);
		bgfx::frame();
	}

	void Draw(Model model, bgfx::ProgramHandle shader)
	{
		model.Draw(shader);
	}

	void loadModel()
	{

	}
};