#pragma once

#include "../../Core/Modules/ModuleBase.hpp"

constexpr const char* CAMERA_MODULE_NAME = "CAMERA";

class CameraModule final : public ModuleBase
{
public:
	explicit CameraModule(ModulesManager* const modules, HooksManager* const hooks, Config& cfg);

	void Run();
	void Shutdown();

private:
	float* pCameraOrtho = nullptr;
};