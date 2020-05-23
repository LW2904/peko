#pragma once

#include "common.h"
#include "sdk/entities.h"

namespace interfaces {
	// Initializes client.
	void initialize();

	extern sdk::engine_client *engine;
	extern sdk::base_client_dll *client;
	extern sdk::client_entity_list *entity_list;
}
