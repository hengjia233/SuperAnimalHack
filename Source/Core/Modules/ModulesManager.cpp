#include "ModulesManager.hpp"

ModulesManager::ModulesManager(HooksManager& hooks)
	: m_hooks(hooks), m_cfg()
{}

void ModulesManager::Init()
{
	for (const auto& module : m_modules)
	{
		module->Init();
	}
}

void ModulesManager::Run()
{
	for (const auto& module : m_modules)
	{
		module->Run();
	}
}

void ModulesManager::Shutdown()
{
	for (const auto& module : m_modules)
	{
		module->Shutdown();
	}
}

Config& ModulesManager::GetConfig() noexcept
{
	return m_cfg;
}
