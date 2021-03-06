#pragma once
#include<stack>
#include "GameState.h"
#include "checkML.h"

class GameStateMachine
{
private:
	stack<GameState*> states;
public:
	GameStateMachine();
	~GameStateMachine();

	GameState* currentState()
	{
		return states.top();
	}

	void popState()
	{
		if (!states.empty())
		{
			delete states.top();

			states.pop();
		}
	}

	void pushState(GameState* state)
	{
		states.push(state);
	}

	void changeState(GameState* state)
	{
		popState();
		pushState(state);
	}
};

