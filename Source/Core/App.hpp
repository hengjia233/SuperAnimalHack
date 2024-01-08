#pragma once
#include "Logging/LogManager.hpp"
#include "Hooks/HooksManager.hpp"
#include "Modules/ModulesManager.hpp"
#include <memory>

class App final
{
public:
	App();

	void Init();
	void AddModules();
	void Run();
	void Shutdown();

private:
	LogManager m_logs;
	HooksManager m_hooks;
	ModulesManager m_modules;
};
