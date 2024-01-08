#pragma once
#include "../../Core/Modules/ModuleBase.hpp"
#include "../../Core/Memory/NopBuffer.hpp"

constexpr const char* SPEEDHACK_MODULE_NAME = "SPEEDHACK";

class SpeedhackModule final : public ModuleBase
{
public:
	explicit SpeedhackModule(ModulesManager* const modules, HooksManager* const hooks, Config& cfg);

	void Run();
	void Shutdown() override;

private:
	void PatchSpeed(float val);

private:
	float* m_jumpSpeedMultiplier;
	const float m_jumpDefaultSpeedMultiplier = 46.0f;
};