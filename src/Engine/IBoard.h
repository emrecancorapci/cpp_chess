#pragma once
#include <string>

namespace engine
{
	class IBoard
	{
	public:
		virtual ~IBoard() = default;
		virtual void new_board() = 0;

		virtual bool update(const std::string& from, const std::string& target) = 0;
		virtual bool check_move(const std::string& home, const std::string& target) = 0;
		virtual void draw(const std::string& message) const = 0;

		virtual bool is_playable(const std::string& pos) const = 0;
		virtual void change_turn() = 0;
	};
}
