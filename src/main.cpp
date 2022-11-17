#include "Engine/ChessEngine.h"
#include "config.h"
#include "Engine/Modes/Classic/Classic.h"

int main()
{
	Config config;
	Classic classic(config.getLogger(), config.getMsgHandler());

	const auto engine = new ChessEngine
	(
		classic.getBoard(),
		classic.getStateFactory(),
		config.getMsgHandler()
	);

	engine->run();
}
