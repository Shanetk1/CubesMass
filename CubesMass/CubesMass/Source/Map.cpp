#include "Map.h"
#include "TextureLoader.h"
#include <fstream>
Map::Map()
{
}

Map::~Map()
{
}

void Map::loadMap(std::string path, int sizeX, int sizeY)
{
	char tile;
	std::fstream mapFile;
	mapFile.open(path);


	int srcX, srcY;

	for (int y = 0; y < sizeY; y++)
	{

		for (int x = 0; x < sizeX; x++)
		{
			mapFile.get(tile);
			
			srcY = atoi(&tile) * 32; 
			mapFile.get(tile);
			srcX = atoi(&tile) * 32;



			Scene1::addTile(srcX, srcY, x * 32, y * 32);
			mapFile.ignore();
		}

	}
	mapFile.close();
}


