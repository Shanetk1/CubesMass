#include "Graph.h"


Graph::Graph(int numNodes_)
{
	nodes.resize(numNodes_);

	for (int i = 0; i < numNodes_; i++)
	{
		nodes[i].resize(numNodes_);

		for (int j = 0; j < numNodes_; j++)
		{

			nodes[i][j] = 0.0f;
		}
	}


}
int Graph::numNodes()
{
	return nodes.size();
}



void Graph::clearWeights()
{
	for (unsigned i = 0; i < nodes.size(); i++)
	{
		for (unsigned j = 0; j < nodes.size(); j++)
		{
			nodes[i][j] = 0;
		}
	}
}

void Graph::addWeightedConnection(int fromNode_, int toNode_, float weight_)
{
	nodes[fromNode_][toNode_] = weight_;
}

std::list<int> Graph::neighbours(int fromNode_)
{
	std::list<int> result = {};
	std::vector<float> toNodes = nodes[fromNode_];
	for (unsigned j = 0; j < toNodes.size(); j++)
	{

		if (nodes[fromNode_][j] > 0.0)
		{
			result.push_back(j);
		}
	}
	return result;



}

std::vector<int> Graph::findPathUsingAStar(int startNode_, int endNode_)
{
	float new_cost;
	int current;

	
}