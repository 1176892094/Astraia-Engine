#pragma once
#include "Log.h"

#if defined(_WIN32) || defined(_WIN64)
#define ASTRAIA_API __declspec(dllexport)
#else
#define ASTRAIA_API __attribute__((visibility("default")))
#endif

#ifdef AE_ENABLE_ASSERTS
#define AE_ASSERT(x, ...){ if(!(x)){ AE_ERROR("Assertion Failed: {0}",__VA_ARGS__); __debugbreak();}}
#define AE_CORE_ASSERT(x, ...){ if(!(x)){ AE_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__); __debugbreak();}}
#else
#define AE_ASSERT(x, ...)
#define AE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << (x))