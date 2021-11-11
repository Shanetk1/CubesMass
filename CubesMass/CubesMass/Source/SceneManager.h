#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <string>
#include "MouseEventListener.h"
class SceneManager
{
	//This class will be how our game runs, 
	//Needs window and tick classes 
private:
	class Window* window = nullptr;
	class Timer* timer = nullptr;
	class Scene* currentScene = nullptr;



	bool isRunning = false;
	unsigned int fps = 0;
public:
	SceneManager();
	~SceneManager();
	void Run();
	bool Initialize(std::string name_, int width_, int height_);
	void GetEvents();
	bool InitializeScene();

};
#endif // !SCENEMANAGER_H