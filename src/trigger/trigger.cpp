#include "trigger.h"

namespace trigger {
	constexpr auto IN_ATTACK = 1;

	void hook(sdk::c_usercmd *cmd) {
		const auto local_player = *reinterpret_cast<sdk::c_base_player **>(csgo::client_base
			+ hazedumper::signatures::dwLocalPlayer);
		const auto crosshair_id = local_player->in_cross();

		if (!crosshair_id)
			return;

		const auto entity = reinterpret_cast<sdk::c_base_player *>(
			reinterpret_cast<uintptr_t>(interfaces::client)
			+ hazedumper::signatures::dwEntityList + (0x10 * crosshair_id));

		if (!entity || entity->get_team() == local_player->get_team())
			return;

		cmd->buttons |= IN_ATTACK;
	}
}
