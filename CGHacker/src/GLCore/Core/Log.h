#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace GLCore {

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};

}

// Client log macros
#define CG_TRACE(...)         ::GLCore::Log::GetLogger()->trace(__VA_ARGS__)
#define CG_INFO(...)          ::GLCore::Log::GetLogger()->info(__VA_ARGS__)
#define CG_WARN(...)          ::GLCore::Log::GetLogger()->warn(__VA_ARGS__)
#define CG_ERROR(...)         ::GLCore::Log::GetLogger()->error(__VA_ARGS__)
#define CG_CRITICAL(...)      ::GLCore::Log::GetLogger()->critical(__VA_ARGS__)
