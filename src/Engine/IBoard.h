#pragma once

class IBoard
{
public:
	virtual void new_board();

	virtual bool update(const std::string& from, const std::string& target);
	virtual bool check_move(const std::string& home, const std::string& target);
	virtual void draw(const std::string& message) const;

	virtual bool is_playable(const std::string& pos, const bool& is_turn_white) const;
};
