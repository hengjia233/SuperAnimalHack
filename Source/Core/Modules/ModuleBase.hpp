#pragma once

#include "../Config/Config.hpp"
#include <string>

class HooksManager;
class ModulesManager;

class ModuleBase
{
public:
	explicit ModuleBase(
		const std::string& name, 
		ModulesManager* const modules,
		HooksManager* const hooksManager, 
		Config& config
	)
		: cfg(config), 
		modules(modules), 
		hooks(hooksManager),
		name(name)
	{}

	virtual ~ModuleBase() {}

	virtual void Init() {};
	virtual void Run() = 0;
	virtual void Shutdown() {};

	const std::string& GetName()
	{
		return name;
	}

protected:
	Config& cfg;
	std::string name;
	HooksManager* const hooks;
	ModulesManager* const modules;
};
