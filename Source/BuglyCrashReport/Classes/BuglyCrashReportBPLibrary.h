#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "BuglyCrashReportBPLibrary.generated.h"


UCLASS()
class BUGLYCRASHREPORT_API UBuglyCrashReportBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = BuglyCrashReport, DisplayName = "BuglyCrashReport Force Crash")
	static void ForceCrash();

	UFUNCTION(BlueprintCallable, Category = BuglyCrashReport, DisplayName = "BuglyCrashReport Force Exception")
	static void ForceException();

	UFUNCTION(BlueprintCallable, Category = BuglyCrashReport, DisplayName = "BuglyCrashReport Set User Identifier")
	static void SetUserIdentifier(FString Identifier);
};
