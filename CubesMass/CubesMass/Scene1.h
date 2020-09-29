#ifndef SCENE1_H
#define SCENE1_H
#include "Scene.h"


class Scene1 : public Scene
{






	//Inherited functions...
	virtual bool OnCreate() override;
	virtual void OnDestroy() override;
	virtual void Update(const float deltaTime) override ;
	virtual void Render()const override;
	virtual void HandleEvents(const SDL_Event& sdlEvent) override;
};





#endif // !SCENE1_H
