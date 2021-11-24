#include "Map.h"
#include "TextureLoader.h"
#include <fstream>
Map::Map(){}
Map::~Map(){}
std::vector<std::vector<TileDemo*>> Map::loadMap(std::string path, int columns, int rows)
{

	//For map file parsing
	char tile;
	std::fstream mapFile;
	mapFile.open(path);
	int srcX, srcY, srcZ;


	//For pathfinding
	std::vector<std::vector<TileDemo*>> tiles;

	tiles.resize(rows);	//first set the size of the rows 
	int node = 0;



	for (int row = 0; row < rows; row++) //Is also equal to rows
	{


		tiles[row].resize(columns);		//Update size of the columns for this current row

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

			TileDemo* t;
			Vector2 position = Vector2(col * 64.0f, row * 64.0f);
			t = new TileDemo(node, 64, 64, position, !srcZ);
			tiles[row][col] = t;

			node++;
		}
	}
	mapFile.close();

	return tiles;
}





