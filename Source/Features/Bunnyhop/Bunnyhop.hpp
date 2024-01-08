#pragma once
#include "../../Core/Modules/ModuleBase.hpp"

constexpr const char* BUNNYHOP_MODULE_NAME = "BUNNYHOP";

class BunnyhopModule final : public ModuleBase
{
public:
	explicit BunnyhopModule(ModulesManager* const modules, HooksManager* const hooks, Config& cfg);

	void Run();
};