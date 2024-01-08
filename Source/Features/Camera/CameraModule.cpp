#include "CameraModule.hpp"
#include "../../Core/Hooks/HooksManager.hpp"

CameraModule::CameraModule(ModulesManager* const modules, HooksManager* const hooks, Config& cfg)
	: ModuleBase(CAMERA_MODULE_NAME, modules, hooks, cfg)
{
}

void CameraModule::Run()
{
	const GameContext& ctx = hooks->GetGameContext();
	
	if (ctx.localPlayer && ctx.localPlayer->player)
	{
		if (cfg.bZoomOverride)
		{
			if (!pCameraOrtho)
			{
				pCameraOrtho = &ctx.localPlayer->player->gameCamera->mainOrthoSize;
			}

			*pCameraOrtho = cfg.fZoomOverrideValue;
		}
		else
		{
			if (pCameraOrtho)
			{
				*pCameraOrtho = cfg.fZoomDefaultValue;
			}
		}
	}
	else
	{
		pCameraOrtho = nullptr;
	}
}

void CameraModule::Shutdown()
{
	if (pCameraOrtho)
	{
		*pCameraOrtho = cfg.fZoomDefaultValue;
	}
}
