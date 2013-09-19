#pragma once
//Action Base is not meant to be created directly, it should be inherited and built upon
//BoardController is watching for a target type


enum place {NONE = 0, RING, ROW, SINGLE, ALL, SURROUNDING, RANDOM};
enum tileAction {SWAP, DESTROY, RANDOMIZE, ROTATE};


struct target{
	place area;
	tileAction what;
	int radius;
};

class ActionBase
{
public:
	
	//overrride to make the action do something
	virtual place action();


private:

	ActionBase(void);
	~ActionBase(void);

};

