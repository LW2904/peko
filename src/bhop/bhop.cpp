#include "bhop.h"

namespace bhop {
	constexpr int ON_GROUND = (1<<0);

	void hook(sdk::c_usercmd *cmd) {
		auto local_player = *reinterpret_cast<sdk::c_base_player **>(csgo::client_base
			+ hazedumper::signatures::dwLocalPlayer);

		if (cmd->buttons & sdk::IN_JUMP && !(local_player->get_flags() & ON_GROUND)) {
			// Remove the jump button from the user command when we are in the air
			cmd->buttons &= ~sdk::IN_JUMP;
		}
	}
}
