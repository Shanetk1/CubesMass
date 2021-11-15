#ifndef CONNECTION_H
#define CONNECTION_H


#include "../Node.h"

class Connection
{
public:
	Connection();
	~Connection();




	void getCost();
private:
	Node* fromNode = nullptr;
	Node* toNode = nullptr;

};




#endif // !CONNECTION_H
