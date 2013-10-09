#pragma once
class RuneModel
{
public:


	RuneModel(void);
	~RuneModel(void);

	float rotation;
	float scale;
	float depth;

	//open ports
	bool top;
	bool bottom;
	bool right;
	bool left;
};

