#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H
#include <SDL_image.h>
#include "Scene1.h"
class TextureLoader
{
public:
	//Should be utilized only ONCE for same images/sources!
	static SDL_Texture* LoadTexture(const char* fileName);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip_);
};
#endif // !TEXTURELOADER_h