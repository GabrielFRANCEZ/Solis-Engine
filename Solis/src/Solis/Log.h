#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Solis {
	class SOLIS_API Log
	{
	public:
		Log();
		~Log();

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger; 

	};

}

//Macros for the core Log
#define SL_CORE_ERROR(...)		::Solis::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SL_CORE_WARN(...)		::Solis::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SL_CORE_INFO(...)		::Solis::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SL_CORE_TRACE(...)		::Solis::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SL_CORE_FATAL(...)		::Solis::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Macros for the client Log
#define SL_CLIENT_ERROR(...)	::Solis::Log::GetClientLogger()->error(__VA_ARGS__)
#define SL_CLIENT_WARN(...)		::Solis::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SL_CLIENT_INFO(...)		::Solis::Log::GetClientLogger()->info(__VA_ARGS__)
#define SL_CLIENT_TRACE(...)	::Solis::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SL_CLIENT_FATAL(...)	::Solis::Log::GetClientLogger()->fatal(__VA_ARGS__)



