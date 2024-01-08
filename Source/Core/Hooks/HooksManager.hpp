#pragma once
#include "../GameStructs/GameStructs.hpp"
#include <Windows.h>
#include <vector>

class ModulesManager;

class HooksManager final
{
private:
	friend class App;
	HooksManager();

	void Init(ModulesManager* modules);
	void EnableHooks();
	void DisableHooks();
	void Shutdown();

	class GraphicsContext
	{
	public:
		HWND hwnd;
		struct ID3D11Device* pDevice = nullptr;
		struct IDXGISwapChain* pSwapchain = nullptr;
		struct ID3D11DeviceContext* pContext = nullptr;
		struct ID3D11RenderTargetView* pRTV = nullptr;
		bool bMenuOpen = false;
	
		void Init(IDXGISwapChain* pSwapChain);
		void InitImGui();
		void ShutdownImGui();
		void InitImGuiStyles();

		bool IsImGuiInited();

	private:
		bool m_inited = false;
		bool m_imguiInited = false;
	} m_graphicsContext;

private:
	ModulesManager* m_modules;
	GameContext m_gameContext;

public:
	Vector3 WorldToScreenPoint2(void* camera, const Vector3& point) const;
	void NetworkPlayerBunnyhopPerformed2(void* pNetworkPlayer) const;

	GraphicsContext& GetGraphicsContext() noexcept;
	const GameContext& GetGameContext() const noexcept;

	ModulesManager* const GetModules() const noexcept;
};
