#pragma once
#include "IState.h"
#include "../ChessBoard.h"
#include "StateDecide.h"
#include "StateMove.h"

#include <map>

class StateFactory
{
private:
	std::map<GameState, IState*> map_state;
public:
	explicit StateFactory(IBoard* board);

	IState* set_state(const GameState& state_name);

	static GameState get_state_decide() { return GameState::decide; }
	static GameState get_state_select() { return GameState::select; }
	static GameState get_state_move() { return GameState::move; }
	static GameState get_state_exit() { return GameState::exit; }
};
