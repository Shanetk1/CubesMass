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
	
	//A thought is I could make the renderer static so instead of 
	//Every class needing to be sent it I could just access it from the global scope...
	SDL_Renderer* renderer = nullptr;



};





#endif // !SCENE1_H
