#include <string>
#include "SceneManager.h"

int main(int argc, char * args[])
{
	std::string name = { "Cube's Mass Game Engine" };
	SceneManager* gsm = new SceneManager();
	if (gsm->Initialize(name, 1000, 840))
	{
		gsm->Run();
	}
	delete gsm;
	return 0;
}