#pragma once

#if defined(_WIN32) || defined(_WIN64)
#define ASTRAIA extern "C" __declspec(dllexport)
#else
#define ASTRAIA extern "C" __attribute__((visibility("default")))
#endif

namespace Astraia
{
    ASTRAIA void Print();
}
