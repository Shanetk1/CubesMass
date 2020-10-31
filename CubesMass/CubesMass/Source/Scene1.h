#ifndef SCENE1_H
#define SCENE1_H
#include "Scene.h"
struct SDL_Renderer;
struct SDL_Rect;
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


	static SDL_Renderer* renderer;
	static SDL_Rect camera;
private:




};





#endif // !SCENE1_H
