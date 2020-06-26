#include "common.h"

namespace csgo {
	uintptr_t client_base = 0;

	void initialize() {
		client_base = client_base = reinterpret_cast<uintptr_t>(
			GetModuleHandle("client.dll"));

		debug::log("> initialized common variables\n");
	}
}
