#ifndef SCENE1_H
#define SCENE1_H
#include "Scene.h"
struct SDL_Renderer;
class GameObject;
class Scene1 : public Scene
{
public:
	Scene1(SDL_Renderer *renderer_);
	//Inherited functions...
	virtual bool OnCreate() override;
	virtual void OnDestroy() override;
	virtual void Update(const float deltaTime) override ;
	virtual void Render()const override;
	virtual void HandleEvents(const SDL_Event& sdlEvent) override;

private:
	SDL_Renderer* renderer = nullptr;
	GameObject* player = nullptr;
};





#endif // !SCENE1_H
