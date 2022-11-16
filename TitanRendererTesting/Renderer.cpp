std::ifstream i("config.ini");
	json configFile;
	i >> configFile;
#if defined(USE_OPENGL)
	glViewport(0, 0, width, height);
#elif defined(USE_D3D11)

#elif defined(USE_D3D12)

#elif defined(USE_VULKAN)

#elif defined(USE_METAL)

#endif

switch (configFile["Display"]["Backend"])
        {
                case "OpenGL":
#define USE_OPENGL
                        break;
                case "Vulkan":
#define USE_VULKAN
                        break;
                case "DirectX11":
#define USE_D3D11
                        break;
                case "DirectX12":
#define USE_D3D12
                        break;
                case "Metal":
#define USE_METAL
                        break;
        }   





#ifdef USE_OPENGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#else
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
#endif
