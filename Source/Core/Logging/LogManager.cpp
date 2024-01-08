#include "LogManager.hpp"
#include <iostream>
#include <Windows.h>
#include <spdlog/spdlog.h>

void LogManager::Init() noexcept
{
#ifndef NDEBUG
    AllocConsole();
    freopen_s(&m_f, "CONOUT$", "w", stdout);
    spdlog::set_level(spdlog::level::debug);
#else
    spdlog::set_level(spdlog::level::off);
#endif
}

void LogManager::Shutdown() noexcept
{
#ifndef NDEBUG
    FreeConsole();
#pragma warning(suppress : 6387)
    fclose(m_f);
#endif
}
