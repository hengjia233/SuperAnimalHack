#include "HooksManager.hpp"
#include "HooksImplementations.hpp"
#include "../Modules/ModulesManager.hpp"
#include <Windows.h>
#include <MinHook.h>
#include <spdlog/spdlog.h>
using namespace HooksDefinitions;

#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>

constexpr const char* ASSEMBLY_NAME = "GameAssembly.dll";

#define CREATE_HOOK(a) \
mh_status = MH_CreateHook(p##a, &Hk##a, reinterpret_cast<LPVOID*>(&o##a)); \
if (mh_status != MH_OK) \
{ \
	spdlog::error("Fail while creating a \"{}\" hook: {}", #a, MH_StatusToString(mh_status)); \
}

#define CREATE_HOOK_2(a) \
mh_status = MH_CreateHook(o##a, &Hk##a, reinterpret_cast<LPVOID*>(&o##a)); \
if (mh_status != MH_OK) \
{ \
	spdlog::error("Fail while creating a \"{}\" hook: {}", #a, MH_StatusToString(mh_status)); \
}

HooksManager::HooksManager()
	: m_gameContext(), m_modules(nullptr)
{}

void HooksManager::Init(ModulesManager * modules)
{
	InitHooksDependencies(this, &m_gameContext);
	m_modules = modules;

	uintptr_t appBase = reinterpret_cast<uintptr_t>(GetModuleHandle(ASSEMBLY_NAME));
	
	WorldToScreenPoint = reinterpret_cast<T_WorldToScreenPoint>(appBase + offsetWorldToScreenPoint);
	pLocalPlayerStart = reinterpret_cast<T_LocalPlayerStart>(appBase + offsetLocalPlayerStart);
	pNetworkPlayerStart = reinterpret_cast<T_NetworkPlayerStart>(appBase + offsetNetworkPlayerStart);
	pNetworkPlayerDestroy = reinterpret_cast<T_NetworkPlayerDestroy>(appBase + offsetNetworkPlayerDestroy);

	MH_STATUS mh_status;
	if (MH_Initialize() != MH_OK)
	{
		spdlog::error("Failed to initialize MinHook. Hooks will not be initialized.");
		return;
	}

	CREATE_HOOK(LocalPlayerStart);
	CREATE_HOOK(NetworkPlayerStart);
	CREATE_HOOK(NetworkPlayerDestroy);
	CREATE_HOOK_2(SwapChainPresent);
	CREATE_HOOK_2(ResizeBuffers);
	CREATE_HOOK_2(SetFullscreenState);

	spdlog::debug("All hooks initialized.");
}

void HooksManager::EnableHooks()
{
	MH_EnableHook(MH_ALL_HOOKS);
}

void HooksManager::DisableHooks()
{
	m_modules->GetConfig().bUnloadCheat = true;
	Sleep(500);
	while (!m_modules->GetConfig().bRenderFinished);
	Sleep(500);

	SetWindowLongPtr(m_graphicsContext.hwnd, GWLP_WNDPROC, (LONG_PTR)oWndProc);

	MH_DisableHook(MH_ALL_HOOKS);
}

void HooksManager::Shutdown()
{
	MH_Uninitialize();
}

Vector3 HooksManager::WorldToScreenPoint2(void* camera, const Vector3& point) const
{
	return WorldToScreenPoint(camera, point);
}

HooksManager::GraphicsContext& HooksManager::GetGraphicsContext() noexcept
{
	return m_graphicsContext;
}

const GameContext& HooksManager::GetGameContext() const noexcept
{
	return m_gameContext;
}

ModulesManager* const HooksManager::GetModules() const noexcept
{
	return m_modules;
}

void HooksManager::GraphicsContext::Init(IDXGISwapChain* pSwapChain)
{
	if (!m_inited)
	{
		this->pSwapchain = pSwapChain;
		this->pSwapchain->GetDevice(__uuidof(ID3D11Device), reinterpret_cast<void**>(&pDevice));
		pDevice->GetImmediateContext(&pContext);

		DXGI_SWAP_CHAIN_DESC sd;
		this->pSwapchain->GetDesc(&sd);
		hwnd = sd.OutputWindow;

		ID3D11Texture2D* pBackBuffer;
		this->pSwapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
		if (!pBackBuffer)
		{
			throw std::runtime_error("Failed to create render target view");
		}

		pDevice->CreateRenderTargetView(pBackBuffer, nullptr, &pRTV);
		pBackBuffer->Release();
	
		while (!oWndProc)
		{
			if (!hwnd) continue;

			oWndProc = (WNDPROC)SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)HkWndProc);
		}

		m_inited = true;
	}
}

void HooksManager::GraphicsContext::InitImGui()
{
	if (!m_inited || m_imguiInited) return;
	if (!hwnd) return;

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.IniFilename = nullptr;
	io.Fonts->AddFontDefault();

	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplDX11_Init(pDevice, pContext);

	InitImGuiStyles();

	m_imguiInited = true;
}

void HooksManager::GraphicsContext::ShutdownImGui()
{
	if (m_inited)
	{
		if (pRTV)
		{
			pRTV->Release();
			pRTV = nullptr;
		}
		if (pSwapchain)
		{
			pSwapchain->Release();
			pSwapchain = nullptr;
		}
		if (pDevice)
		{
			pDevice->Release();
			pDevice = nullptr;
		}
		if (pContext)
		{
			pContext->Release();
			pContext = nullptr;
		}

		m_inited = false;
	}

	if (m_imguiInited)
	{
		ImGui_ImplDX11_Shutdown();
		ImGui_ImplWin32_Shutdown();
		ImGui::DestroyContext();

		m_imguiInited = false;
	}
}

void HooksManager::GraphicsContext::InitImGuiStyles()
{
	ImGui::StyleColorsDark();
}

bool HooksManager::GraphicsContext::IsImGuiInited()
{
	return m_imguiInited && m_inited;
}
