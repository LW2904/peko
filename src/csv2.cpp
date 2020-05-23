#include "csv2.h"

DWORD WINAPI initialize(void *instance) {
	auto cleanup = [&] {
		debug::log("> cleaning up\n");

		hooks::release();

		// Wait a bit so any running hooks can finish.
		std::this_thread::sleep_for(std::chrono::milliseconds (250));
		debug::log("> exiting\n");
		FreeLibraryAndExitThread(static_cast<HMODULE>(instance), 0);
	};

	// Wait for the last .dll to have loaded.
	while (!GetModuleHandleA("serverbrowser.dll"))
		std::this_thread::sleep_for(std::chrono::milliseconds(250));

	try {
		debug::log("> root@fsoc.space\n");
		debug::log("> initializing\n");

		hooks::initialize();

		while (!GetAsyncKeyState(VK_END)) {
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}

		cleanup();
	} catch (const std::exception &err) {
		// TODO: If debug::log throws the error this won't be particularly helpful.
		debug::log("fatal error: %s\n", err.what());

		cleanup();
	}

	return 0;
}

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved) {
	if (reason == DLL_PROCESS_ATTACH) {
		auto handle = CreateThread(nullptr, NULL, initialize, instance,
			NULL, nullptr);
		if (handle) {
			CloseHandle(handle);
		} else {
			MessageBoxA(nullptr, "Failed creating thread", "Error", MB_ICONERROR);
		}
	}

	return TRUE;
}
