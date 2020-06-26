#include "interfaces.h"

namespace interfaces {
	sdk::engine_client *engine = nullptr;
	sdk::base_client_dll *client = nullptr;
	sdk::client_mode *client_mode = nullptr;
	sdk::client_entity_list *entity_list = nullptr;

	template<typename T>
	T *get_interface(const std::string &mod_name, const std::string &int_name) {
		auto create_interface = reinterpret_cast<void *(*)(const char *, int *)>(
			GetProcAddress(GetModuleHandle(mod_name.c_str()), "CreateInterface")
		);

		if (!create_interface) {
			throw std::runtime_error("failed getting create_interface");
		}

		return reinterpret_cast<T *>(
			create_interface(int_name.c_str(), nullptr)
		);
	}

	void initialize() {
		engine = get_interface<sdk::engine_client>("engine.dll", "VEngineClient014");
		client = get_interface<sdk::base_client_dll>("client.dll", "VClient018");
		entity_list = get_interface<sdk::client_entity_list>("client.dll",
			"VClientEntityList003");

		// TODO: This is really ghetto.
		client_mode = **reinterpret_cast<sdk::client_mode ***>(
			(*reinterpret_cast<uintptr_t **>(client))[10] + 5);

		debug::log("> initialized interfaces\n");
	}
}
