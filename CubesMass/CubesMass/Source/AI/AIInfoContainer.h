#ifndef AIINFOCONTAINER_H
#define AIINFOCONTAINER_H




class AIInfoContainer
{
public:
	//Not even used for the AI but conveys information about the AI's states and such....
	friend class AIController;
	AIInfoContainer() : seesPlayer(false)
	{

	}


	bool getSeesPlayer() { return seesPlayer; }
	void setSeesPlayer(bool newVal) { seesPlayer = newVal; }


private:
	//Values for decisionmaking operations....
	bool seesPlayer;




};


#endif // !AIINFOCONTAINER_H
