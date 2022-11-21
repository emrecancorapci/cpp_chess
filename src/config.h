#pragma once
#include "Engine/Helpers/Logger.h"
#include "Engine/Helpers/MessageHandler.h"

class Config
{
private:
	Logger* _logger = new Logger;
	MessageHandler* _msgHandler = new MessageHandler;
public:
	Logger* get_logger() const { return _logger; }
	MessageHandler* get_msg_handler() const { return _msgHandler; }
};