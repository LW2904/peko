#include "glow.h"

namespace glow {
	glow_object_manager *manager = nullptr;

	void initialize() {
		manager = reinterpret_cast<glow_object_manager *>(csgo::client_base
			+ hazedumper::signatures::dwGlowObjectManager);
	}

	void hook() {
		if (!enabled) {
			return;
		}

		if (!manager) {
			initialize();
			return;
		}

		for (int i = 0; i < manager->glow_object_definitions.size; i++) {
			glow_object_definition &glow_object = manager->glow_object_definitions[i];

			if (glow_object.next_free_slot != ENTRY_IN_USE) {
				continue;
			}

			int team = glow_object.entity->get_team();

			// This should filter out everything that's not a player.
			if (!team) {
				continue;
			}

			switch (team) {
				case 2:
					glow_object.r = 0.89019f;
					glow_object.g = 0.23137f;
					glow_object.b = 0.23137f;
					break;
				case 3:
					glow_object.r = 0.23921f;
					glow_object.g = 0.55294f;
					glow_object.b = 0.89019f;
					break;
				default:
					break;
			}

			glow_object.glow_alpha = 1.0f;
			glow_object.render_when_occluded = true;
			glow_object.bloom_amount = 0.5f;
		}
	}
};
