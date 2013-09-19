#pragma once

#include "ActionHopperModel.h"
#include "ActionHopperView.h"
#include "BoardController.h"
#include "ActionBase.h"

class ActionHopperController
{
public:
	ActionHopperController(ActionHopperModel model, ActionHopperView view, BoardController board);
	~ActionHopperController(void);

	//returns useable hopper slots
	int hopperSlots();

	void update(double deltaTime);

	//for registering to EventWatcher
	void attemptActionOnQ();
	void attemptActionOnW();
	void attemptActionOnE();
	void attemptActionOnR();

	//What the user is attempting
	bool actionIsQueued();
	ActionBase actionQueued();

private:
	//A GREAT deal of the actionhopper will be private

	//make hopper from scratch
	void generateHopper();

	//adds Action to Queue
	void advanceHopper();

	//continues action(s) in progress
	void progressAction(double deltaTime);

	//the player can only have one action linked to the mouse at a time
	void selectHopper(int index);

	//allows for other actions (player presses a key when one is already mapped)
	void switchHopper(int index);

	//Mapped action is dropped
	void executeHopper();

	//Hopper's data.
	ActionHopperModel model;
};

