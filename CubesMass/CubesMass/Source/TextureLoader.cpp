#include "TextureLoader.h"

SDL_Texture* TextureLoader::LoadTexture(const char* fileName, SDL_Renderer* renderer)
{
    //Create a surface I think or something from image yup
  




    SDL_Surface* surf = IMG_Load(fileName);
                  

    
    SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, surf);
    
    SDL_FreeSurface(surf);
    
    
    return text;
}
