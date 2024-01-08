#pragma once
#include "ModuleBase.hpp"
#include <list>

class ModulesManager final
{
public:
	explicit ModulesManager(HooksManager& hooks);

	void Init();
	void Run();
	void Shutdown();

	Config& GetConfig() noexcept;

	template<typename T, typename ...Args>
	void AddModule(Args&& ...args)
	{
		m_modules.push_back(std::make_shared<T>(this, &m_hooks, m_cfg, &args...));
	}

	template<typename T>
	T* const GetModule(const std::string& name) noexcept
	{
		for (auto& module : m_modules)
		{
			if (module->GetName() == name)
			{
				return reinterpret_cast<T*>(module.get());
			}
		}

		return nullptr;
	}

private:
	std::list<std::shared_ptr<ModuleBase>> m_modules;
	HooksManager& m_hooks;
	Config m_cfg;
};
