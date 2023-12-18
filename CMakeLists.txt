cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Sokoban")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Sokoban "Sokoban.cpp" "include/SokobanEngine.h" "include/LevelGenerator.h" "include/Game.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Sokoban PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
