#ifndef MAP_H

#define MAP_H

#include <SDL.h>
#include <string>
class Map
{
public:
	Map();
	~Map();

	static void loadMap(std::string path, int sizeX, int sizeY);




};


#endif MAP_H

