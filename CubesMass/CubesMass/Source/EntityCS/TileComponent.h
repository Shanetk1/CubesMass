#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H

#include "Components.h"
#include <SDL.h>
class TileComponent : public Component
{
private: 
	SDL_Texture* texture = nullptr;
	SDL_Rect dRect;
public:
	Vector2 position = position;
	TileComponent() = default;
	SDL_Rect sRect;

	TileComponent(int Srcx, int Srcy, int Posx, int Posy, SDL_Texture* tex_)
	{
		//tex = TextureLoader::LoadTexture(path);
		//Bad
		texture = tex_;
		sRect.x = Srcx;
		sRect.y = Srcy;

		sRect.w = sRect.h = 32;

		dRect.x = Posx;
		dRect.y = Posy;

		position.x = Posx;
		position.y = Posy;

		//We scale the map here basically doubling its size... 
		//So normally our map is 800x640 but now it is 
		dRect.w = dRect.h = 64;


	}
	~TileComponent()
	{
		SDL_DestroyTexture(texture);
	}
	void Render() override
	{
		TextureLoader::Draw(texture, sRect, dRect, 0.0f, SDL_FLIP_NONE);
	}
	void Update(const float deltaTime) override
	{
		dRect.x = position.x - Scene1::camera.x;
		dRect.y = position.y - Scene1::camera.y;
	}

};


#endif // !TILECOMPONENT_H
