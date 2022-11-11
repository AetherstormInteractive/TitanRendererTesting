#include "BGFXRenderer.h"

#define WINDOWS

namespace Renderer
{
	int BGFXRenderer::Setup(GLFWwindow* win, nlohmann::json configFile, bool is_fullscreen)
	{
		bgfx::PlatformData platformData;
		bgfx::setPlatformData(platformData);

		uint16_t m_pciId = 0;

		bgfx::Init init;
		init.type = bgfx::RendererType::Count;
		init.vendorId = m_pciId;
#ifdef WINDOWS
		init.platformData.nwh = glfwGetWin32Window(win);
#elif LINUX
	#ifdef X11
		init.platformData.nwh = glfwGetX11Window(win);
	#else
		init.platformData.nwh = glfwGetWaylandWindow(win);
	#endif
#endif

		init.platformData.ndt = glfwGetPrimaryMonitor();

		init.resolution.width = is_fullscreen ? configFile["Display"]["FullscreenWidth"] : configFile["Display"]["WindowedWidth"];
		init.resolution.height = is_fullscreen ? configFile["Display"]["FullscreenHeight"] : configFile["Display"]["WindowedHeight"];

		init.resolution.reset = BGFX_RESET_VSYNC;
		bgfx::init(init);

		bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);
		bgfx::setViewRect(0, 0, 0,
			is_fullscreen ? configFile["Display"]["FullscreenWidth"] : configFile["Display"]["WindowedWidth"],
			is_fullscreen ? configFile["Display"]["FullscreenHeight"] : configFile["Display"]["WindowedHeight"]);
		
		// TODO add model here


		return 0;
	}

	void BGFXRenderer::Run(nlohmann::json configFile, bool is_fullscreen)
	{


		const bx::Vec3 at = { 0.0f, 0.0f,  0.0f };
		const bx::Vec3 eye = { 0.0f, 0.0f, -5.0f };
		float view[16];
		bx::mtxLookAt(view, eye, at);
		float proj[16];
		bx::mtxProj(proj, 60.0f, 
			float(is_fullscreen ? configFile["Display"]["FullscreenWidth"] : configFile["Display"]["WindowedWidth"]) / 
			float(is_fullscreen ? configFile["Display"]["FullscreenHeight"] : configFile["Display"]["WindowedHeight"]), 
			0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);

		bgfx::setViewTransform(0, view, proj);

		// TODO draw model here 

		bgfx::touch(0);
		bgfx::frame();
	}
}
