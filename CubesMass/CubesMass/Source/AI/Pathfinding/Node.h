#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include "Node.h"

class Node
{
public:
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


