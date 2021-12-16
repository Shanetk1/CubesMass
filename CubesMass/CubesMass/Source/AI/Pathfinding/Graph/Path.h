#ifndef PATH_H
#define PATH_H

#include "../../../Vector.h"
#include <vector>

struct Path
{
	//Contains current 

	//Defaults to 0 
	std::vector<TileDemo*> vectorList;

	

	int currentIndex = 0;
	int currentNode = 0;



	Path()
	{
		//vectorList = path;
		//currentNode = path[path.size() - 1];
		//currentIndex = path.size() - 1;

		vectorList = std::vector<TileDemo*>();


		//Now our path its 
		//vectorList = path;
		//currentNode = path.size();
		//currentIndex = vectorList.size() - 1;



		

	}
	void setPathDirection(std::vector<TileDemo*> path)
	{
		vectorList = path;
		currentIndex = vectorList.size() - 1;
	}

	

	Vector2 getCurrentNodePosition()
	{
		//This will need to know about the tile map....
		
		//From this we can find our values its hard to do however....

/*
		for (int i = 0; i < 20; i++)
		{
			//Loop through the tilesize until we find the node 
		
			for (int j = 0; j < 25; j++)
			{
				//
				if (tiles_[i][j]->getNode() == currentNode)
				{
					return tiles_[i][j]->getPosition();
				}
			}
		}*/

		return vectorList[currentIndex]->getPosition();


		//I think this is redundant since both of the represenations are the same
		/*
		for (int i = 0; i < 500; i++)
		{
			//Loop thru thing
			if (tiles_[i]->getNode() == currentNode)
			{
				return tiles_[i]->getPosition();
			}
		}*/

	}
	


	void incrementCurrentNode(int inc_)
	{
		//Meaning go to the next node in the list or path

		if (currentIndex + inc_  < vectorList.size())
		{
			//currentNode = vectorList[currentIndex - inc_];
			currentIndex = currentIndex + inc_;
			//Update node as well...
		}
		else
		{
			printf("Error");
		}
	}

	void decrementCurrentNode(int inc_)
	{
		//Meaning go to the next node in the list or path

		if (currentIndex - inc_ < vectorList.size())
		{
			//currentNode = vectorList[currentIndex - inc_];
			currentIndex = currentIndex - inc_;
			//Update node as well...
		}
		else
		{
			printf("Error");
		}
	}


};




#endif // !PATH_H
