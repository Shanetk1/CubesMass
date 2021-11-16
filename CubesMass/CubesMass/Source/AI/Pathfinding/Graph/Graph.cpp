#include "Graph.h"
#include <math.h>

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



struct ComparePriority
{
	bool operator () (PrioNode &lhs, PrioNode &rhs)
	{
		return lhs.getPriority() > rhs.getPriority();
	}
};



std::vector<int> Graph::findPathUsingAStar(int startNode_, int endNode_)
{
	float new_cost;
	int current;


	PrioNode* currentPrioNode;
	currentPrioNode = new PrioNode(startNode_, 0.0f);


	std::priority_queue<PrioNode, std::deque<PrioNode>, ComparePriority > frontier;
	frontier.push(*currentPrioNode);



	std::vector<int> came_from;
	came_from.resize(numNodes());

	std::map<int, float> cost_so_far;
	cost_so_far[startNode_] = 0.0f;



	while (!frontier.empty())
	{
		//Grabs then pops from the queue since this is now checked
		current = frontier.top().node;
		frontier.pop();

		
		if (current == endNode_)
		{
			//Awesome job done 
			break;
		}
		for (int next : neighbours(current))
		{
			new_cost = cost_so_far[current] + next;
			//Check if a particular value is the key of a map //Either key_comp or find, or contains
			//Pretty sure contains works but its for c++ 20
			auto search = cost_so_far.find(next);
			if (search == cost_so_far.end() || new_cost < cost_so_far[next])
			{
				//Found something with this correstponding key
				cost_so_far[next] = new_cost;
				float priority = new_cost + heuristic(endNode_, next);
				frontier.push(*new PrioNode(next, priority));
				came_from[next] = current;
			}
		}

	}




	return came_from;
}

float Graph::heuristic(int node_, int goal_)
{
	//Using manhattan distance!

	//I wonder if we get our true location of these nodes in world space to 
	//calulate this.....

	//float dX, dY;

	

	//dX = abs(node_)




	return 0.0f;
}
