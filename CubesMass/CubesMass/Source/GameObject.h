#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include <SDL.h>
class GameObject
{
public:
	GameObject(const char* fileName, SDL_Renderer* renderer_, float x, float y);
	~GameObject();

	void Update();
	void Render();


private:

	float xPos = 0;
	float yPos = 0;

	//List of things/components ALL our gameobjects will have
	SDL_Texture* texture = nullptr;

	SDL_Rect srcRect, destRect;
	//This is just our window's renderer necessary for drawing our texture + easier if we have it as a private variable within our class
	SDL_Renderer* renderer = nullptr;
};


#endif // !GAMEOBJECT_H

