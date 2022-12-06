#ifndef VULKAN_RENDERER_H
#define VULKAN_RENDERER_H

#include <stdio.h>
#include <stdlib.h>
#include <optional>

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_vulkan.h>

#include <vulkan/vulkan.h>

#include <nlohmann/json.hpp>

#include "../../Renderer.h"

struct QueueFamilyIndices
{
	std::optional<uint32_t> graphicsFamily;

	bool isComplete()
	{
		return graphicsFamily.has_value();
	}
};

class VulkanRenderer : public Renderer
{
public:
	void createInstance();
	bool checkValidationLayerSupport();
	void pickPhysicalDevice();
	bool isDeviceSuitable(VkPhysicalDevice device);
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	void createLogicalDevice();

	int Initialize(nlohmann::json configFile, int windowMode);
	void Update(float deltaTime, int windowMode);
	void Draw();
	void Shutdown();

private:
#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif
	const std::vector<const char*> validationLayers =
	{
		"VK_LAYER_KHRONOS_validation"
	};
	VkInstance instance;

	VkDevice device;

	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkPhysicalDeviceProperties deviceProperties{};
	VkPhysicalDeviceFeatures deviceFeatures{};

	VkQueue graphicsQueue;
};
#endif