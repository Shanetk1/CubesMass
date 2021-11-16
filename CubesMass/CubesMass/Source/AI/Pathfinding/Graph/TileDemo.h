#ifndef TIMEDEMO_H
#define TIMEDEMO_H


#include <SDL.h>
#include "../../../Vector.h"
class TileDemo
{
public:
	TileDemo();
	TileDemo(int node_, float width_, float height_, Vector2 position_);
	~TileDemo();
	void Render(SDL_Renderer* renderer_, int xAxisPixel, int yAxisPixel);
	int getNode() { return node; };
private:
	float width, height;
	Vector2 position;
	int node;

};


#endif // !TIMEDEMO_H


