cmake_minimum_required (VERSION 3.8)
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("SuperAnimalHack")

FILE(GLOB_RECURSE AppSources
	Source/**.hpp
	Source/**.cpp
)

FILE(GLOB_RECURSE ImGuiSources
	Deps/ImGui/*.h
	Deps/ImGui/*.cpp
)

add_library (SuperAnimalHack MODULE ${AppSources})
target_include_directories(SuperAnimalHack PRIVATE Deps/MinHook/include)
target_link_libraries(SuperAnimalHack PRIVATE d3d11)
target_sources(SuperAnimalHack PRIVATE Deps/MinHook/src/buffer.c Deps/MinHook/src/buffer.h Deps/MinHook/src/hook.c Deps/MinHook/src/trampoline.c Deps/MinHook/src/trampoline.h Deps/MinHook/src/hde/hde32.c Deps/MinHook/src/hde/hde32.h Deps/MinHook/src/hde/hde64.c Deps/MinHook/src/hde/hde64.h Deps/MinHook/src/hde/pstdint.h Deps/MinHook/src/hde/table32.h Deps/MinHook/src/hde/table64.h)
target_sources(SuperAnimalHack PRIVATE ${ImGuiSources})
target_include_directories(SuperAnimalHack PRIVATE Deps/ImGui)

add_subdirectory(Deps/spdlog)
add_subdirectory(Deps/json-develop)

target_link_libraries(SuperAnimalHack PRIVATE spdlog)
target_link_libraries(SuperAnimalHack PRIVATE nlohmann_json::nlohmann_json)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SuperAnimalHack PROPERTY CXX_STANDARD 20)
endif()
