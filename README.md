# Note: This project is unfinished and was created for educational purposes

# Thanks to ThirdParty libraries developers
* NlohmannJSON
* MinHook
* ImGui
* spdlog

# Tools used in the development
HexRays IDA Pro
CheatEngine 7.5
ReClass .NET
ilSpy
Il2CppDumper
de4dot

# Realized features
* Camera zoom
* ESP (snaplines)
* No recoil
* Speedhack
* Simple logging

# Unfinished features
* Perfect jump
* Aimbot
* Box esp
* Mine esp
* OOF arrows on near targets
* Crash reports logging

# Note
All function offsets are in **Source/Core/Hooks/HooksDefinitions.hpp**.
All structure offsets are in **Source/Core/GameStructs/GameStructs.hpp**.

# Warning
NEVER use 
```c++
#include "Source/Core/Hooks/HooksImplementations.hpp"

or

#include "Source/Core/Hooks/HooksDefinitions.hpp"
```
IT CALLS UNRESOLVED EXTERNAL CHARACTERS.

# Rendering
All logic related to rendering takes place in the file at the path **Source/Core/Hooks/HooksImplementations.hpp** in the function **HooksDefinitions::HkSwapChainPresent**

# Config & Modules
The **Source/Core/Config/Config.hpp** file contains the module states. Modules (software functionality) in their turn are located in **Source/Features/[MODULE_NAME]/[MODULE_NAME].hpp** or **Source/Features/[MODULE_NAME]/[MODULE_NAME].cpp** folder

# Hooks
All application hooks are declared in **HooksDefinitions.hpp**, their implementation in **HooksImplementations.hpp**, and their initialization in **HooksManager.cpp** (**Init()** method)
