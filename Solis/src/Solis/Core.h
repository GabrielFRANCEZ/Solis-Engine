#pragma once

#ifdef SL_PLATFORM_WINDOWS
	#ifdef SL_BUILD_DLL
		#define SOLIS_API __declspec(dllexport)
	#else
		#define SOLIS_API __declspec(dllimport)
	#endif
#else
	#error Solis only support windows for the moment
#endif