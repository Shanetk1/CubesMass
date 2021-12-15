#include "Map.h"
#include "TextureLoader.h"
#include <fstream>
Map::Map(){}
Map::~Map(){}
std::vector<TileDemo*> Map::loadMap(std::string path, int columns, int rows)
{

	//For map file parsing
	char tile;
	std::fstream mapFile;
	mapFile.open(path);
	int srcX, srcY, srcZ;


	//For pathfinding
	std::vector<TileDemo*> tiles;

	tiles.resize(rows * columns);
	int node = 0;



	for (int row = 0; row < rows; row++) //Is also equal to rows
	{


				//Update size of the columns for this current row

		for (int col = 0; col < columns; col++)//Is also equal to columns
		{
			mapFile.get(tile);
			srcY = atoi(&tile) * 32;
			mapFile.get(tile);
			srcX = atoi(&tile) * 32;
			mapFile.get(tile);
			srcZ = atoi(&tile);




			//We end up scaling the map up doubling its size...
			Scene1::addTile(srcX, srcY, col * 64, row * 64, srcZ);


			mapFile.ignore();
			//Create grid for pathfinding here as well.....


			//Logic for tile creation



			//I want position to be represented different here.... since nodes are represented as 500... i want this as well it makes it very easy....
			TileDemo* t;
			Vector2 position = Vector2(col * 64, row * 64);
			//We add 32 here to the position to have the nodes position be at the cetre of the tile
			t = new TileDemo(node, 64, 64, position, !srcZ);
			int tmp = (col) + (row * columns);
			//std::cout << tmp << std::endl;
			tiles[tmp] = t;

			node++;
		}
	}


	mapFile.close();

	return tiles;
}





