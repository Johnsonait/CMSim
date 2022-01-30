#pragma once

#include <memory.h>

#include "Core.h"
#include "spdlog/spdlog.h"


namespace CMSim {

	class CMSIM_API Log
	{

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }


	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;	
	};

}

//Core logging macros
#define CMS_CORE_TRACE(...)     ::CMSim::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CMS_CORE_INFO(...)      ::CMSim::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CMS_CORE_WARN(...)      ::CMSim::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CMS_CORE_ERROR(...)     ::CMSim::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CMS_CORE_FATAL(...)     ::CMSim::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client logging macros
#define CMS_TRACE(...)          ::CMSim::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CMS_INFO(...)           ::CMSim::Log::GetClientLogger()->info(__VA_ARGS__)
#define CMS_WARN(...)           ::CMSim::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CMS_ERROR(...)          ::CMSim::Log::GetClientLogger()->error(__VA_ARGS__)
#define CMS_FATAL(...)          ::CMSim::Log::GetClientLogger()->fatal(__VA_ARGS__)
