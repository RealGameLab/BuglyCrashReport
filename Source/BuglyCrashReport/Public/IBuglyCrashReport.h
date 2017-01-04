#pragma once

#include "ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogBuglyCrashReport, Log, All);

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
