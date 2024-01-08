#pragma once
#include <cstdint>
#include "../Math/Vectors.hpp"
#include <d3d11.h>

namespace HooksDefinitions
{
	typedef HRESULT(__stdcall* T_SwapChainResizeBuffers)(IDXGISwapChain* pSwapChain, const UINT BufferCount, const UINT Width, const UINT Height, const DXGI_FORMAT NewFormat, const UINT SwapChainFlags);
	typedef HRESULT(__stdcall* T_SwapChainSetFullscreenState)(IDXGISwapChain* pSwapChain, const BOOL FullScreen, IDXGIOutput* pTarget);
	typedef HRESULT(__stdcall* T_SwapChainPresent)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
	typedef void(__fastcall* T_NetworkPlayerRollPerformed)(void* pNetworkPlayer, bool b1, bool b2, bool b3);
	typedef void(__fastcall* T_NetworkPlayerStart)(void* pNetworkPlayer, int16_t playerId, int8_t b1);
	typedef Vector3(__fastcall* T_WorldToScreenPoint)(void* camera, Vector3 point);
	typedef void(__fastcall* T_NetworkPlayerDestroy)(void* pNetworkPlayer);
	typedef void(__fastcall* T_LocalPlayerStart)(void* pLocalPlayer);
	
	T_SwapChainSetFullscreenState oSetFullscreenState = nullptr;
	T_NetworkPlayerDestroy pNetworkPlayerDestroy = nullptr;
	T_NetworkPlayerDestroy oNetworkPlayerDestroy = nullptr;
	T_NetworkPlayerStart pNetworkPlayerStart = nullptr;
	T_NetworkPlayerStart oNetworkPlayerStart = nullptr;
	T_SwapChainResizeBuffers oResizeBuffers = nullptr;
	T_WorldToScreenPoint WorldToScreenPoint = nullptr;
	T_SwapChainPresent oSwapChainPresent = nullptr;
	T_LocalPlayerStart pLocalPlayerStart = nullptr;
	T_LocalPlayerStart oLocalPlayerStart = nullptr;
	WNDPROC oWndProc = nullptr;
	
	uintptr_t offsetNetworkPlayerDestroy = 0x13987E0;
	uintptr_t offsetNetworkPlayerStart = 0x139EA30;
	uintptr_t offsetWorldToScreenPoint = 0xB97C10;
	uintptr_t offsetLocalPlayerStart = 0x12674A0;

	HRESULT __stdcall HkResizeBuffers(IDXGISwapChain* pSwapChain, const UINT BufferCount, const UINT Width, const UINT Height, const DXGI_FORMAT NewFormat, const UINT SwapChainFlags);
	HRESULT __stdcall HkSetFullscreenState(IDXGISwapChain* pSwapChain, const BOOL FullScreen, IDXGIOutput* pTarget);
	HRESULT __stdcall HkSwapChainPresent(IDXGISwapChain* pSwapChain, UINT syncInterval, UINT flags);
	void __fastcall HkNetworkPlayerStart(void* pNetworkPlayer, int16_t playerId, int8_t b1);
	LRESULT APIENTRY HkWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void __fastcall HkNetworkPlayerDestroy(void* pNetworkPlayer);
	void __fastcall HkLocalPlayerStart(void* pLocalPlayer);

	const constexpr unsigned int SWAPCHAIN_FULLSCREEN_INDEX = 10u;
	const constexpr unsigned int SWAPCHAIN_PRESENT_INDEX = 8u;
	const constexpr unsigned int SWAPCHAIN_RESIZE_INDEX = 13u;

}
