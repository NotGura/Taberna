#pragma once

#ifdef TB_PLATFORM_WINDOWS
	#ifdef TB_BUILD_DLL 
		#define TABERNA_API __declspec(dllexport)
	#else
		#define TABERNA_API __declspec(dllimport)
	#endif

#endif // 
