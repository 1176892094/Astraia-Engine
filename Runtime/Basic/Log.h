#pragma once
#include "memory"
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Basic
{
    class ASTRAIA_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

#define AE_CORE_TRACE(...):: Basic::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AE_CORE_INFO(...):: Basic::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AE_CORE_WARN(...):: Basic::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AE_CORE_ERROR(...):: Basic::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AE_CORE_FATAL(...):: Basic::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define AE_TRACE(...):: Basic::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AE_INFO(...):: Basic::Log::GetClientLogger()->info(__VA_ARGS__)
#define AE_WARN(...):: Basic::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AE_ERROR(...):: Basic::Log::GetClientLogger()->error(__VA_ARGS__)
#define AE_FATAL(...):: Basic::Log::GetClientLogger()->fatal(__VA_ARGS__)
