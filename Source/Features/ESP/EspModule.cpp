#include "EspModule.hpp"
#include "../../Core/Hooks/HooksManager.hpp"
#include "../../Core/Math/Utils.hpp"
#include <spdlog/spdlog.h>

#include <imgui.h>

EspModule::EspModule(ModulesManager* const modules, HooksManager* const hooks, Config& cfg)
	: ModuleBase(ESP_MODULE_NAME, modules, hooks, cfg)
{}

void EspModule::Run()
{
}

void EspModule::Draw()
{
	if (cfg.bEsp)
	{
		Sleep(5); // Made to remove textures blicks
		const auto& ctx = hooks->GetGameContext();
		if (!ctx.localPlayer) return;
		
		const size_t playersCount = ctx.players.size();

		for (auto* target : ctx.players)
		{
			if (!target) continue;
			if (target == ctx.localPlayer->player) continue;
			if (target->playerIsDead) continue;

			if (cfg.bSnaplines && playersCount > 0)
			{
				const auto& localPlayerPos = ctx.localPlayer->player->pos;
				const auto& targetPos = target->pos;

				const auto& distanceToTarget = Utils::Sign(
					Vector2(
						localPlayerPos.x - targetPos.x,
						localPlayerPos.y - targetPos.y
					)
				);

				const auto& screenLocalPlayerPos = hooks->WorldToScreenPoint2(ctx.localPlayer->camera, Vector3(localPlayerPos.x, localPlayerPos.y, 0.0f));
				const auto& screenTargetPos = hooks->WorldToScreenPoint2(ctx.localPlayer->camera, Vector3(targetPos.x, targetPos.y, 0.0f));

				const auto& maxDistance = cfg.fMaxSnaplineRenderDistance;
				const auto& nearDistance = cfg.fNearSnaplineRenderDistance;
				if (distanceToTarget.x > maxDistance && distanceToTarget.y > maxDistance) continue;

				ImU32 color = (distanceToTarget.x <= nearDistance && distanceToTarget.y <= nearDistance)
					? ImGui::ColorConvertFloat4ToU32(ImVec4(0.0f, 1.0f, 0.0f, 1.0f))
					: ImGui::ColorConvertFloat4ToU32(ImVec4(1.0f, 0.0f, 0.0f, 1.0f));

				ImGui::GetWindowDrawList()->AddLine(
					{ screenLocalPlayerPos.x, screenLocalPlayerPos.y },
					{ screenTargetPos.x, ImGui::GetIO().DisplaySize.y - screenTargetPos.y - 15.0f },
					color
				);
			}
		}
	}
}
