#ifndef PCH_H
#define PCH_H

#include <windows.h>
#include <thread>

#include "SDK/Basic.hpp"

#include "SDK/FortniteGame_classes.hpp"
#include "SDK/Engine_classes.hpp"
#include "SDK/CoreUObject_classes.hpp"
#include "SDK/FortniteGame_structs.hpp"
#include "SDK/Engine_structs.hpp"
#include "SDK/CoreUObject_structs.hpp"
using namespace SDK;

namespace Configuration {
	static inline bool bRespawn = true;
	static inline bool bConsole = true;
};

#endif 
