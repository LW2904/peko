#pragma once

#include "common.h"
#include "sdk/sdk.h"

namespace interfaces {
	// Initializes client.
	void initialize();

	extern sdk::base_client_dll *client;
	extern sdk::client_mode *client_mode;
	// These are unused now but I figured I'd keep them around for the future.
	extern sdk::engine_client *engine;
	extern sdk::client_entity_list *entity_list;
}
