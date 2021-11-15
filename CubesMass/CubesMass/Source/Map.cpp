#include "Map.h"
#include "TextureLoader.h"
#include <fstream>
Map::Map(){}
Map::~Map(){}
void Map::loadMap(std::string path, int sizeX, int sizeY)
{
	char tile;
	std::fstream mapFile;
	mapFile.open(path);
	int srcX, srcY, srcZ;
	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapFile.get(tile);
			srcY = atoi(&tile) * 32; 
			mapFile.get(tile);
			srcX = atoi(&tile) * 32;
			mapFile.get(tile);
			srcZ = atoi(&tile);

			Scene1::addTile(srcX, srcY, x * 64, y * 64, srcZ);
			//Create grid for pathfinding here as well.....



			mapFile.ignore();
		}
	}
	mapFile.close();
}


