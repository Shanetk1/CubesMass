#include "TextureLoader.h"
SDL_Texture* TextureLoader::LoadTexture(const char* fileName)
{
    //Create a surface I think or something from image yup
    SDL_Surface* surf = IMG_Load(fileName);
    SDL_Texture* text = SDL_CreateTextureFromSurface(Scene1::renderer, surf); 
    SDL_FreeSurface(surf); 
    return text;
}

void TextureLoader::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, float angle, SDL_RendererFlip flip_)
{
    angle *= RADIANS_TO_DEGREES;
    SDL_RenderCopyEx(Scene1::renderer, tex, &src, &dest, static_cast<double>(angle), NULL, flip_);
}
