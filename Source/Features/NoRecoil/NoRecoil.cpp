#include "NoRecoil.hpp"
#include <Windows.h>
#include <spdlog/spdlog.h>

NoRecoilModule::NoRecoilModule(ModulesManager* const modules, HooksManager* const hooks, Config& cfg)
	: ModuleBase(NORECOIL_MODULE_NAME, modules, hooks, cfg), 
	m_buffer((uintptr_t)GetModuleHandle("GameAssembly.dll") + 0x12A0BE1, 7u)
{}

void NoRecoilModule::Run()
{
	if (cfg.bNoRecoil)
	{
		m_buffer.Nop();
	}
	else
	{
		m_buffer.Restore();
	}
}
