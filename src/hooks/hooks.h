#pragma once

#include "common.h"

#include "MinHook.h"

#include "sdk/sdk.h"
#include "bhop/bhop.h"
#include "glow/glow.h"
#include "trigger/trigger.h"
#include "interfaces/interfaces.h"

namespace hooks {
	namespace frame_stage_notify {
		enum client_frame_stage_t {
			// Haven't run any frames yet
			FRAME_UNDEFINED = -1,
			FRAME_START,
			// A network packet is being received
			FRAME_NET_UPDATE_START,
			// Data has been received and we're going to start calling PostDataUpdate
			FRAME_NET_UPDATE_POSTDATAUPDATE_START,
			// Data has been received and we've called PostDataUpdate on all data recipients
			FRAME_NET_UPDATE_POSTDATAUPDATE_END,
			// We've received all packets, we can now do interpolation, prediction, etc..
			FRAME_NET_UPDATE_END,
			// We're about to start rendering the scene
			FRAME_RENDER_START,
			// We've finished rendering the scene.
			FRAME_RENDER_END
		};

		using proto = void (__thiscall *)(void *, client_frame_stage_t);
		extern proto original;

		void __fastcall hook(void *thisptr, void *edx,
			client_frame_stage_t stage);
	}

	namespace create_move {
		using proto = bool (__stdcall *)(float, sdk::c_usercmd *);
		extern proto original;

		bool __fastcall hook(void* ecx, void* edx, int input_sample_frametime, sdk::c_usercmd* cmd);
	}

	void initialize();

	void release();
}
