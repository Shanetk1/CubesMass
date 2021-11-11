#include "SceneManager.h"
#include "Window.h"
#include "Timer.h"
#include "Scene1.h"
SceneManager::SceneManager()
{
	window = nullptr;
	timer = nullptr;
	currentScene = nullptr;
	fps = 60;
	isRunning = false;
}
SceneManager::~SceneManager(){}
bool SceneManager::Initialize(std::string name_, int width_, int height_)
{
	window = new Window();
	if (!window->OnCreate(name_, width_, height_))
	{
		return false;
	}


	SDL_WarpMouseInWindow(window->getWindow(), window->getWidth() / 2, window->getHeight() / 2);

	MouseEventListener::RegisterWindow(window);


	timer = new Timer();
	if (timer == nullptr)
	{
		return false;
	}
	if (!InitializeScene())
	{
		return false;
	}
	return true;
}
void SceneManager::Run()
{
	timer->Start();
	isRunning = true;
	while (isRunning)
	{
		timer->UpdateFrameTicks();
		GetEvents();//This includes currentscene->handlevents
		currentScene->Update(timer->GetDeltaTime());
		currentScene->Render();
		
		SDL_Delay(timer->GetSleepTime(fps));
	}
	currentScene->OnDestroy();
}

void SceneManager::GetEvents()
{
	//Create scene switching and control for closing/quitting the window
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent))
	{
		currentScene->HandleEvents(sdlEvent);
		if (sdlEvent.type == SDL_EventType::SDL_QUIT)
		{
			isRunning = false;//Set is running false then close window
			return;
		}

		switch (sdlEvent.type)
		{
		case SDL_MOUSEBUTTONDOWN:
			MouseEventListener::Update(sdlEvent);
			break;
		case SDL_MOUSEBUTTONUP:
			MouseEventListener::Update(sdlEvent);
			break;
		case SDL_MOUSEMOTION:
			MouseEventListener::Update(sdlEvent);
			break;
		case SDL_MOUSEWHEEL:
			MouseEventListener::Update(sdlEvent);
			break;

		default:
			break;
		}



		/*
					case SDL_SCANCODE_ESCAPE:
						isRunning = false;
						return;

					case SDL_SCANCODE_1:
						InitializeScene();
						break;*/

	}
}

bool SceneManager::InitializeScene()
{
	if (currentScene != nullptr)
	{
		delete currentScene;
		currentScene = nullptr;
	}
	currentScene = new Scene1(window->getRenderer());
	return currentScene->OnCreate();
}