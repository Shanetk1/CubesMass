#include "TileDemo.h"
#include "../../../Scene1.h"

TileDemo::TileDemo(): width(0.0f), height(0.0f), position(Vector2())
{
}


TileDemo::TileDemo(int node_, float width_, float height_, Vector2 position_, bool canTraverse_)
{
	width = width_;
	height = height_;
	position = position_;
	node = node_;
	canTraverse = canTraverse_;
}

TileDemo::~TileDemo()
{
}

void TileDemo::Render(SDL_Renderer* renderer_, int xAxisPixel, int yAxisPixel)
{
	Vector2 screenCoords;

	


	//screenCoords.x = position.x - 1.0f * width;//- camera pos
	//screenCoords.y = position.y - 1.0f * height;//- camera pos

	//screenCoords.x -= Scene1::camera.x;
	//screenCoords.y -= Scene1::camera.y;




	SDL_Rect rect;
	rect.w = width;
	rect.h = height;


	//This moves based on camera 

		//screenCoords.x -= Scene1::camera.x;
	//screenCoords.y -= Scene1::camera.y;

	rect.x = position.x - Scene1::camera.x;
	rect.y = position.y - Scene1::camera.y;



	SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);




	
	
	
	
	SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255);

	if (!canTraverse)
	{
		SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);


	}
	//SDL_RenderFillRect(renderer_, &rect);

	SDL_RenderDrawRect(renderer_, &rect);
}
