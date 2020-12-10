#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H

#include "Components.h"
#include <SDL.h>
class TileComponent : public Component
{
public: 
	SDL_Texture* tex;
	SDL_Rect srcRect, dstRect;

	TileComponent() = default;

	TileComponent(int Srcx, int Srcy, int Posx, int Posy, const char* path)
	{
		tex = TextureLoader::LoadTexture(path);

		srcRect.x = Srcx;
		srcRect.y = Srcy;

		srcRect.w = srcRect.h = 32;

		dstRect.x = Posx;
		dstRect.y = Posy;

		dstRect.w = dstRect.h = 32;

	}
	~TileComponent()
	{
		SDL_DestroyTexture(tex);
	}
	void Render() override
	{
		TextureLoader::Draw(tex, srcRect, dstRect, SDL_FLIP_NONE);
	}


};


#endif // !TILECOMPONENT_H
