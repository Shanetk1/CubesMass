#ifndef PRIONODE_H
#define PRIONODE_H

//Used specifically from our graph class...
class PrioNode
{
public:
	PrioNode(int node_, float priority_);

	inline float getPriority() { return priority; }


public:
	int node;
	float priority;
};


#endif // !ASTARNODE_H


