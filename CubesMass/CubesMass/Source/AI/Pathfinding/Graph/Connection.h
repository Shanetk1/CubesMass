#ifndef CONNECTION_H
#define CONNECTION_H


#include "../Node.h"

class Connection
{
public:
	Connection();
	~Connection();




	int getCost() { return cost; }
private:
	Node* fromNode = nullptr;
	Node* toNode = nullptr;
	int cost = 1;
};




#endif // !CONNECTION_H
