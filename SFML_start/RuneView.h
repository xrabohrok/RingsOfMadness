//Rune Models will keep track of the data in a Rune

#pragma once
class RuneView
{
public:
	RuneView(void);
	~RuneView(void);

private:
	float rotation;
	float scale;
	float depth;

	//open ports
	bool top;
	bool bottom;
	bool right;
	bool left;
};

