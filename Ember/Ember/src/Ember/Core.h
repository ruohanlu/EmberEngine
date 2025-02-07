#pragma once

#ifdef EB_PLATFORM_WINDOWS
	#ifdef EB_BUILD_DLL
		#define EMBER_API __declspec(dllexport)
	#else
		#define EMBER_API __declspec(dllimport)
	#endif
#else
	#error Ember only support windows!
#endif

#ifdef EB_DEBUG
#define EB_ENABLE_ASSERTS
#endif

#ifdef EB_ENABLE_ASSERTS
	#define EB_ASSERT(x, ...) { if(!(x)) { EB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define EB_CORE_ASSERT(x, ...) { if(!(x)) { EB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else		
	#define EB_ASSERT(x, ...)
	#define EB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define SIMULUX_LOCAL

#define EB_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)