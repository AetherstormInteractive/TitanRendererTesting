#include <iostream>
#include <fstream>

#include <entt/entt.hpp>

using json = nlohmann::json;
class Scene
{
public:
	json configFile;
	entt::registry registry;

	GLFWwindow* window;
	bool is_fullscreen = false;

	int SceneStart();
	void SceneUpdate();
	int SceneEnd();

	void CreateEntity(entt::entity entity);
	void DeleteEntity(entt::entity entity);

private:
	std::vector<entt::entity> entities;
};
