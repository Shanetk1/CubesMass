#include <string>
#include "SceneManager.h"

int main(int argc, char * args[])
{
	std::string name = { "Cube's Mass Game Engine" };


	//Main Loop
	SceneManager* gsm = new SceneManager();

	if (gsm->Initialize(name, 1280, 720))
	{
		gsm->Run();
	}
	delete gsm;

	return 0;
}