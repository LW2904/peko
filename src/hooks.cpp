#include "hooks.h"

namespace hooks {
	// TODO: The whole hooking infrastructure needs a refactor once it's
	// 	 stable-ish.

	frame_stage_notify::proto frame_stage_notify::original = nullptr;

	void initialize() {
		if (MH_Initialize() != MH_OK) {
			throw std::runtime_error("failed to initialize hooking library");
		}

		interfaces::initialize();

		if (MH_CreateHook(
			(sdk::get_virtual<void *>(interfaces::client, 37)),
			reinterpret_cast<void *>(frame_stage_notify::hook),
			reinterpret_cast<void **>(&frame_stage_notify::original)
		) != MH_OK) {
			throw std::runtime_error("failed to create frame_stage_notify hook");
		}

		if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
			throw std::runtime_error("failed to enable hooks.");
		}

		debug::log("> initialized hooks\n");
	}

	void release() {
		MH_DisableHook(MH_ALL_HOOKS);

		MH_Uninitialize();

		debug::log("> released hooks\n");
	}

	void __fastcall frame_stage_notify::hook(void *thisptr, void *edx,
		client_frame_stage_t stage) {
		// See: https://developer.valvesoftware.com/wiki/Frame_Order
		// if (stage == FRAME_NET_UPDATE_POSTDATAUPDATE_START) {
			glow::hook();
		// }

exit:
		frame_stage_notify::original(thisptr, stage);
	}
}
