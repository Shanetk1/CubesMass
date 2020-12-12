#include <string>
#include "SceneManager.h"

int main(int argc, char * args[])
{
	std::string name = { "Cube's Mass Game Engine" };
	SceneManager* gsm = new SceneManager();
	if (gsm->Initialize(name, 800, 600))
	{
		gsm->Run();
	}
	delete gsm;
	return 0;
}