#include "Engine/ChessEngine.h"
#include "config.h"
#include "Engine/Modes/Classic/config.h"

int main()
{
	const Config config;
	const classic::Config classic(config.get_logger(), config.get_msg_handler());

	const auto engine = new engine::ChessEngine
	(
		classic.get_board(),
		classic.get_state_factory(),
		config.get_msg_handler()
	);

	engine->run();
}
