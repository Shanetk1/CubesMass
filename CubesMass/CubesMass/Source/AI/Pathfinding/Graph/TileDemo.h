#ifndef TIMEDEMO_H
#define TIMEDEMO_H


#include <SDL.h>
#include "../../../Vector.h"



//This needs to transfer into our baseline node class basically...
//Maybe idk but this tiledemo is what holds our information for our map world
class TileDemo
{
public:
	TileDemo();
	TileDemo(int node_, float width_, float height_, Vector2 position_, bool canTraverse_);
	~TileDemo();
	void Render(SDL_Renderer* renderer_, int xAxisPixel, int yAxisPixel);
	int getNode() { return node; };
	bool getCanTraverse() { return canTraverse; };
	Vector2 getPosition() { return position; }
private:
	float width, height;
	Vector2 position;
	int node;
	bool canTraverse;

};


#endif // !TIMEDEMO_H


