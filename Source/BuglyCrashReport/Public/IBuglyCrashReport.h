#pragma once

#include "ModuleManager.h"

class IBuglyCrashReport : public IModuleInterface
{
public:
	static inline IBuglyCrashReport& Get()
	{
		return FModuleManager::LoadModuleChecked< IBuglyCrashReport >("BuglyCrashReport");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("BuglyCrashReport");
	}
};
