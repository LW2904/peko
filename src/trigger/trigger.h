#pragma once

#include "common.h"
#include "sdk/sdk.h"
#include "interfaces/interfaces.h"

namespace trigger {
	void hook(sdk::c_usercmd *cmd);
}
