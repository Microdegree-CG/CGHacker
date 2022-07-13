#include "cgpch.h"

#include "CGHacker/Core/Log.h"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace CG 
{

	Ref<spdlog::logger> Log::s_CoreLogger;
	Ref<spdlog::logger> Log::s_ClientLogger;

	void Log::Init(std::string coreName, std::string clientName, std::string logName)
	{
	  std::vector<spdlog::sink_ptr> logSinks;
	  logSinks.emplace_back(
		  std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
	  logSinks.emplace_back(
		  std::make_shared<spdlog::sinks::basic_file_sink_mt>(logName, true));

	  logSinks[0]->set_pattern("%^[%T] %n: %v%$");
	  logSinks[1]->set_pattern("[%T] [%l] %n: %v");

	  s_CoreLogger =
		  std::make_shared<spdlog::logger>(coreName, begin(logSinks), end(logSinks));
	  spdlog::register_logger(s_CoreLogger);
	  s_CoreLogger->set_level(spdlog::level::trace);
	  s_CoreLogger->flush_on(spdlog::level::trace);

	  s_ClientLogger =
		  std::make_shared<spdlog::logger>(clientName, begin(logSinks), end(logSinks));
	  spdlog::register_logger(s_ClientLogger);
	  s_ClientLogger->set_level(spdlog::level::trace);
	  s_ClientLogger->flush_on(spdlog::level::trace);
	}

} // namespace CG
