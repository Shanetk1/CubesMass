#include "GameObject.h"
#include "TextureLoader.h"

GameObject::GameObject(const char* fileName, SDL_Renderer* renderer_, float x, float y)
{
	renderer = renderer_;
	texture = TextureLoader::LoadTexture(fileName);
	if (texture == nullptr)
	{
		//printf("Bad texture, not created");
	}
	
	xPos = x;
	yPos = y;

	//Where the texture will start to draw
	srcRect.x = xPos;
	srcRect.y = yPos;
	
	//The width and height of the texture basically
	srcRect.w = 32;
	srcRect.h = 32;


}

GameObject::~GameObject()
{
}

void GameObject::Update()
{


	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void GameObject::Render()
{
	SDL_RenderCopy(renderer, texture, &srcRect, &destRect);

}
