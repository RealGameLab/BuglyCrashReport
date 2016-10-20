#include "BuglyCrashReportPrivatePCH.h"
#include "BuglyCrashReportSettings.h"
#include "BuglyCrashReportBPLibrary.h"
#include "ISettingsModule.h"

DEFINE_LOG_CATEGORY(LogBuglyCrashReport);

#define LOCTEXT_NAMESPACE "BuglyCrashReport"

class FBuglyCrashReport : public IBuglyCrashReport
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FBuglyCrashReport, BuglyCrashReport)

void FBuglyCrashReport::StartupModule()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "BuglyCrashReport",
			LOCTEXT("RuntimeSettingsName", "BuglyCrashReport"),
			LOCTEXT("RuntimeSettingsDescription", "Configure the BuglyCrashReport plugin"),
			GetMutableDefault<UBuglyCrashReportSettings>()
		);
	}
}

void FBuglyCrashReport::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
