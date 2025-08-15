#pragma once
#if defined(_WIN32) || defined(_WIN64)
#define ASTRAIA_API __declspec(dllexport)
#else
#define ASTRAIA_API __attribute__((visibility("default")))
#endif

#define BIT(x) (1<<x)
