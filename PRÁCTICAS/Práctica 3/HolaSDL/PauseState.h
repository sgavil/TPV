#pragma once
#include "GameState.h"
#include "Game.h"
#include <vector>
#include "MenuButton.h"
#include "checkML.h"

class PauseState : public GameState
{
private:
	PlayState* playState;
public:
	PauseState(Game* game);
	virtual ~PauseState();
	static void resume(Game* game);
	static void saveGame(Game* game);
	static void goToMenu(Game* game);
};

