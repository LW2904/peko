#pragma once

#include <Windows.h>
#include <stdexcept>
#include "hazedumper.h"

#define DEBUG _DEBUG

namespace debug {
	template<typename... Args>
	inline void log(const char *message, Args... args) {
		// No need to grab this all the time
		static auto Msg = (void (__cdecl *)(const char *, ...))GetProcAddress(
			GetModuleHandle("tier0.dll"), "Msg");

		Msg(message, args...);
	}
}
