#pragma once
#include <string>

class MessageHandler
{
private:
	std::string _message;
public:
	MessageHandler() = default;

	void set_message(const std::string& message) { _message = message; }
	std::string get_message() { return _message; }
};
