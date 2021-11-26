#ifndef MAP_H
#define MAP_H
#include <SDL.h>
#include <string>
#include <vector>
#include "AI/Pathfinding/Graph/TileDemo.h"
class Map
{
public:
	Map();
	~Map();

	//Loads our map from a file and also sets up a tilemap 
	static std::vector<TileDemo*> loadMap(std::string path, int sizeX, int sizeY);



};
#endif MAP_H

