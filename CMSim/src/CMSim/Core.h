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

#ifdef CMS_ENABLE_ASSERTS
	#define CMS_ASSERT(x,...) {if(!(x)) {CMS_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define CMS_CORE_ASSERT(x,...) { if(!(x)) { CMS_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__; __debugbreak();) } }
#else
	#define CMS_ASSERT(x,...)
	#define CMS_CORE_ASSERT(x,...)
#endif

#define BIT(x) (1 << x)