#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Taberna
{

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	
	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("TABERNA");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);


	}

}

//Core log macros
#define TB_CORE_TRACE(...)	::Taberna::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TB_CORE_INFO(...)	::Taberna::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TB_CORE_WARN(...)	::Taberna::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TB_CORE_ERROR(...)	::Taberna::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TB_CORE_FATAL(...)	::Taberna::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros

#define TB_TRACE(...)		::Taberna::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TB_INFO(...)		::Taberna::Log::GetClientLogger()->info(__VA_ARGS__)
#define TB_WARN(...)		::Taberna::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TB_ERROR(...)		::Taberna::Log::GetClientLogger()->error(__VA_ARGS__)
#define TB_FATAL(...)		::Taberna::Log::GetClientLogger()->fatal(__VA_ARGS__)