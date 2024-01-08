#include "Bunnyhop.hpp"
#include "../../Core/Hooks/HooksManager.hpp"
#include <spdlog/spdlog.h>

BunnyhopModule::BunnyhopModule(ModulesManager* const modules, HooksManager* const hooks, Config& cfg)
	: ModuleBase(BUNNYHOP_MODULE_NAME, modules, hooks, cfg)
{}

void BunnyhopModule::Run()
{
	if (cfg.bBhop)
	{
		auto& ctx = hooks->GetGameContext();
	}
}
