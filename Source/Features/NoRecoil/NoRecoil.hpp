#pragma once
#include "../../Core/Modules/ModuleBase.hpp"
#include "../../Core/Memory/NopBuffer.hpp"

constexpr const char* NORECOIL_MODULE_NAME = "NORECOIL";

class NoRecoilModule final : public ModuleBase
{
public:
	explicit NoRecoilModule(ModulesManager* const modules, HooksManager* const hooks, Config& cfg);

	void Run();

private:
	NopBuffer m_buffer;
};