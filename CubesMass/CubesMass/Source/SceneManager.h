#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <string>
class SceneManager
{
	//This class will be how our game runs, 
	//Needs window and tick classes 
public:
	SceneManager();
	~SceneManager();
	void Run();
	bool Initialize(std::string name_, int width_, int height_);
	void GetEvents();
	bool InitializeScene();
private:
	class Window* window;
	class Timer* timer;
	class Scene* currentScene;

	bool isRunning;
	unsigned int fps;


};

#endif // !SCENEMANAGER_H