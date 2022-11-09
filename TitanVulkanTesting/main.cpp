#include "Scene.h"

int main()
{
	Scene* scene = new Scene();
	scene->SceneStart();
	scene->SceneUpdate();
	scene->SceneEnd();
	return 0;
}