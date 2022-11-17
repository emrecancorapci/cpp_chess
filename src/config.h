#pragma once
#include "Engine/Helpers/Logger.h"
#include "Engine/Helpers/MessageHandler.h"
#include "Engine/IBoard.h"

class Config
{
private:
	Logger* logger = new Logger;
	MessageHandler* msgHandler = new MessageHandler;
public:
	Logger* getLogger() { return logger; }
	MessageHandler* getMsgHandler() { return msgHandler; }
};