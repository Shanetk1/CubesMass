#ifndef GRAPH_H
#define GRAPH_H

#include <queue>
#include <vector>
#include <list>
#include <map>
#include "../PrioNode.h"
#include "TileDemo.h"

class Graph
{
public:
	
	//Careful creating graph with this the nodes will not be set up properly!
	Graph();

	~Graph();


	//POPULATING THE GRAPH FUNCTIONS\\
   ///||||||||||||||||||||||||||||||\\\

	//Sets up the graph to hold this amount of nodes...
	Graph(int numNodes);

	//Reset all weights
	int numNodes();

	//Clear weights of node list
	void clearWeights();

	//Add weighted connections from this node to this node and set this specified weight
	void addWeightedConnection(int fromNode_, int toNode_, float weight_);

	//Returns integer value of the weight to travel from this node to this node, might need to change since the weight is a float
	int getWeight(int fromNode_, int toNode_);

	//Returns a light of neighbours connected from this node... Note this just returns node index not weight
	std::list<int> neighbours(int fromNode_);
	
	void addGameWorld(const std::vector<std::vector<TileDemo*>>& ref_);
	



	//Path Finding Functions\\
   ///|||||||||||||||||||||||\\\
	
	//Returns a path to get to the goal node from the start node, the path is just node indices to travel to
	std::vector<int> findPathUsingAStar(int startNode_, int goalNode_);

	//Use manhattan product here still needs implementation WIP
	float heuristic(int node_, int goal_);



	
private:

	//List of nodes with a internal list of weights; the first vector is the node index, the 2nd vector is the weight!
	std::vector<std::vector<float>> nodes;

	
	//I think tilemap is defined wrong since
	//WIP I personally think representing it like this is bad since the nodes are represented in a 1d format and this is a 2d format..... but for now leave it
	//Also, I think this can be represented as a address rather than value?? not sure though...
	std::vector<std::vector<TileDemo*>> gameWorldRef;


	//Graph might need to know about the tilemap....
	// nodes[i][j]
};



#endif // !GRAPH_H
