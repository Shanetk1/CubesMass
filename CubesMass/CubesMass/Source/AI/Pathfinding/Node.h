#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include "Node.h"

class Node
{
public:


	//Meaning our nodes are labelled like , 1, 2, 3, 4, 5.... and so on
	//So instead of loading up every node via a pointer, we could always
	//Load up our graph using a list of integers and define a function here to get label
	int label;


	Node()
	{
		label = 0;
	}
	Node(int i_)
	{
		label = i_;
	}



	void print()
	{
		printf("%i ", label);
	}


};


#endif // !NODE_H


