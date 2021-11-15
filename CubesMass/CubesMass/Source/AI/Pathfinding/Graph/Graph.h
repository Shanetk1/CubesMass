#ifndef GRAPH_H
#define GRAPH_H


#include <vector>
#include <list>

class Graph
{
public:
	Graph();
	~Graph();



	//Array, list of connections to the node given


	Graph(int numNodes)
	{
		nodes.resize(numNodes);
	}

	//Reset all weights
	int numNodes() {}
	void clearWeights() {}
	void addWeightedConnection(int fromNode_, int toNode_, float weight_);
	std::list<int> neighbours(int fromNode_);
	std::vector<int> findPathUsingAStar(int startNode_, int goalNode_);
	float heuristic(int node_, int goal_);



	
private:
	std::vector<std::vector<float>> nodes;
	// nodes[i][j]
};



#endif // !GRAPH_H
