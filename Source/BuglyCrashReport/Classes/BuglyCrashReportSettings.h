#pragma once

#include "BuglyCrashReportSettings.generated.h"

UCLASS(config = Game, defaultconfig)
class UBuglyCrashReportSettings : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Config, EditAnywhere, meta = (DisplayName = "Api ID"))
	FString AppID;

	UPROPERTY(Config, EditAnywhere, meta = (DisplayName = "Api Version"))
	FString AppVersion;

	UPROPERTY(Config, EditAnywhere, meta = (DisplayName = "Api Channel"))
	FString AppChannel;

	UPROPERTY(Config, EditAnywhere, meta = (DisplayName = "Api Enable Debug"))
	bool bAppEnableDebug;
};
