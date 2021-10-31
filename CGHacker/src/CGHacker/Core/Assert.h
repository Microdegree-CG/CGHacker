#pragma once


#include "CGHacker/Core/Base.h"
#include <filesystem>

#ifdef CG_ENABLE_ASSERTS

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and 
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message

	#define CG_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { CG##type##ERROR(msg, __VA_ARGS__);  CG_DEBUGBREAK();}}


	#define CG_INTERNAL_ASSERT_WITH_MSG(type, check, ...)   \
		CG_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)

	#define CG_INTERNAL_ASSERT_NO_MSG(type, check)			\
		CG_INTERNAL_ASSERT_IMPL(type, check, "Assertion `{0}` failed at {1}:{2}", CG_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define CG_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define CG_INTERNAL_ASSERT_GET_MACRO(...) CG_EXPAND_MACRO(CG_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, CG_INTERNAL_ASSERT_WITH_MSG, CG_INTERNAL_ASSERT_NO_MSG))


	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define CG_ASSERT(...) CG_EXPAND_MACRO(CG_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define CG_CORE_ASSERT(...) CG_EXPAND_MACRO(CG_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__))

#else
	#define CG_ASSERT(...)
	#define CG_CORE_ASSERT(...)
#endif





