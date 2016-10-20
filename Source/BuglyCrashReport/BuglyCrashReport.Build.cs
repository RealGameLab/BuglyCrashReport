using System.IO;

namespace UnrealBuildTool.Rules
{
    public class BuglyCrashReport : ModuleRules
    {
        public BuglyCrashReport(TargetInfo Target)
        {
            Definitions.Add("WITH_BUGLYCRASHREPORT=1");

            PrivateIncludePaths.Add("BuglyCrashReport/Private");

            PublicDependencyModuleNames.AddRange(new string[] { "Engine", "Core", "CoreUObject" });
            PrivateIncludePathModuleNames.AddRange(new string[] { "Settings" });

            if (Target.Platform == UnrealTargetPlatform.Android)
            {
                PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });
                string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, BuildConfiguration.RelativeEnginePath);
                AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(PluginPath, "BuglyCrashReport_APL.xml")));
            }
        }
    }
}
