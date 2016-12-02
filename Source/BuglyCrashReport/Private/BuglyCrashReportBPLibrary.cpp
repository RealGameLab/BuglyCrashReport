#include "BuglyCrashReportBPLibrary.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include <android_native_app_glue.h>
#elif PLATFORM_IOS
#endif

void UBuglyCrashReportBPLibrary::ForceCrash()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ForceCrash", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#elif PLATFORM_IOS

#endif
}

void UBuglyCrashReportBPLibrary::ForceException()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ForceException", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#elif PLATFORM_IOS

#endif
}

void UBuglyCrashReportBPLibrary::SetUserIdentifier(FString Identifier)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring IdentifierFinal = Env->NewStringUTF(TCHAR_TO_UTF8(*Identifier));
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_SetUserIdentifier", "(Ljava/lang/String;)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, IdentifierFinal);
		Env->DeleteLocalRef(IdentifierFinal);
	}
#elif PLATFORM_IOS

#endif
}