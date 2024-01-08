#include "Speedhack.hpp"
#include "../../Core/Hooks/HooksManager.hpp"
#include <Windows.h>
#include <spdlog/spdlog.h>

SpeedhackModule::SpeedhackModule(ModulesManager* const modules, HooksManager* const hooks, Config& cfg)
	: ModuleBase(SPEEDHACK_MODULE_NAME, modules, hooks, cfg), m_jumpSpeedMultiplier(nullptr)
{
	uintptr_t addr = (uintptr_t)GetModuleHandle("GameAssembly.dll") + 0x22f11f4;

	m_jumpSpeedMultiplier = &(*(float*)addr);
}

void SpeedhackModule::Run()
{
	auto& ctx = hooks->GetGameContext();
	
	if (cfg.bSpeedhack)
	{
		PatchSpeed(56.0f);
		
		if (ctx.localPlayer && ctx.localPlayer->player)
		{
			ctx.localPlayer->player->bunnyHopCurrentBonus = 0.3f;
		}
	}
	else
	{
		PatchSpeed(m_jumpDefaultSpeedMultiplier);
	
		if (ctx.localPlayer && ctx.localPlayer->player)
		{
			ctx.localPlayer->player->bunnyHopCurrentBonus = 0.1f;
		}
	}
}

void SpeedhackModule::Shutdown()
{
	PatchSpeed(m_jumpDefaultSpeedMultiplier);
}

void SpeedhackModule::PatchSpeed(float val)
{
	if (*m_jumpSpeedMultiplier != val)
	{
		DWORD old;
		VirtualProtect(m_jumpSpeedMultiplier, sizeof(m_jumpSpeedMultiplier), PAGE_EXECUTE_READWRITE, &old);
		*m_jumpSpeedMultiplier = val;
		VirtualProtect(m_jumpSpeedMultiplier, sizeof(m_jumpSpeedMultiplier), old, &old);
	}
}
