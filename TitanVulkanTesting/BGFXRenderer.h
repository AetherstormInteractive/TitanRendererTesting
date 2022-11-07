
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
	void Draw(bgfx::ShaderHandle shader)
	{

	}
};

class Model
{
public:
	std::vector<Mesh> meshes;
	std::string directory;

	void Draw(bgfx::ShaderHandle shader)
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

	void Draw(Model model, bgfx::ShaderHandle shader)
	{
		//model.Draw(shader);
	}

	void loadModel()
	{

	}
};