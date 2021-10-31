#pragma once

#include <memory>

#include "CGHacker/Core/PlatformDetection.h"

#ifdef CG_DEBUG
	#if defined(CG_PLATFORM_WINDOWS)
		#define CG_DEBUGBREAK() __debugbreak()
	#elif defined(CG_PLATFORM_LINUX)
		#include <signal.h>
		#define CG_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
		#define CG_ENABLE_ASSERTS
#else
	#define CG_DEBUGBREAK()
#endif


#define CG_EXPAND_MACRO(x) x
#define CG_STRINGIFY_MACRO(x) #x

namespace CG 
{

	template <typename T> 
	using Scope = std::unique_ptr<T>;
	template <typename T, typename... Args>
	constexpr Scope<T> CreateScope(Args &&... args) 
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template <typename T> 
	using Ref = std::shared_ptr<T>;
	template <typename T, typename... Args>
	constexpr Ref<T> CreateRef(Args &&... args) 
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}	

} // namespace CG
