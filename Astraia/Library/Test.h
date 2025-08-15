#pragma once

#if defined(_WIN32) || defined(_WIN64)
#define ASTRAIA_API __declspec(dllexport)
#else
#define ASTRAIA_API __attribute__((visibility("default")))
#endif

// #if defined(_WIN32) || defined(_WIN64)
// #define ASTRAIA_API extern "C" __declspec(dllexport)
// #else
// #define ASTRAIA_API extern "C" __attribute__((visibility("default")))
// #endif

namespace Runtime
{
    ASTRAIA_API void Print();
}
