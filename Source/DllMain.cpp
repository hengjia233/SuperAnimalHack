#include "main.hpp"

BOOL WINAPI DllMain(HMODULE hMod, DWORD fdwReason, LPVOID lpvReserved) {
    // Perform actions based on the reason for calling.
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hMod);
#pragma warning(suppress : 6387)
        CloseHandle(CreateThread(nullptr, 0u, (LPTHREAD_START_ROUTINE)Main, hMod, 0u, nullptr));
        break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}