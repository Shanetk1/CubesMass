#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H
#include <SDL_image.h>
#include "Scene1.h"
#include <SDL_mixer.h>
class TextureLoader
{
public:
	//Should be utilized only ONCE for same images/sources!
	static SDL_Texture* LoadTexture(const char* fileName);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, float angle, SDL_RendererFlip flip_);
	inline static Mix_Music* LoadSoundTrack(const char* fileName)
	{
		return Mix_LoadMUS(fileName);
	}
	inline static Mix_Chunk* LoadSoundFX(const char* fileName)
	{
		return Mix_LoadWAV(fileName);
	}
};
#endif // !TEXTURELOADER_h