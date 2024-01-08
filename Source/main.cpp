#include "main.hpp"
#include "Core/App.hpp"

DWORD __stdcall Main(HMODULE hMod)
{
	App* app = new App();

	app->AddModules();
	app->Init();
	app->Run();
	app->Shutdown();

	delete app;

	FreeLibraryAndExitThread(hMod, 0u);
	return 0;
}
