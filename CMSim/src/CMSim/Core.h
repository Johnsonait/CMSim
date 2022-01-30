#pragma once

#ifdef CMS_PLATFORM_WINDOWS
	#ifdef CMS_BUILD_DLL
		#define CMSIM_API __declspec(dllexport)
	#else
		#define CMSIM_API __declspec(dllimport)
	#endif
#else
	#error CMSim only supports Windows	
#endif

#define BIT(x) (1 << x)