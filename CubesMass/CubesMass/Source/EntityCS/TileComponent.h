#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H

#include "Components.h"
#include <SDL.h>
class TileComponent : public Component
{
public: 
	SDL_Texture* tex;
	SDL_Rect srcRect, dstRect;
	Vector2 position;
	TileComponent() = default;

	TileComponent(int Srcx, int Srcy, int Posx, int Posy, const char* path)
	{
		tex = TextureLoader::LoadTexture(path);

		srcRect.x = Srcx;
		srcRect.y = Srcy;

		srcRect.w = srcRect.h = 32;

		dstRect.x = Posx;
		dstRect.y = Posy;

		position.x = Posx;
		position.y = Posy;
		dstRect.w = dstRect.h = 64;

	}
	~TileComponent()
	{
		SDL_DestroyTexture(tex);
	}
	void Render() override
	{
		TextureLoader::Draw(tex, srcRect, dstRect, SDL_FLIP_NONE);
	}
	void Update() override
	{
		dstRect.x = position.x - Scene1::camera.x;
		dstRect.y = position.y - Scene1::camera.y;
	}

};


#endif // !TILECOMPONENT_H
