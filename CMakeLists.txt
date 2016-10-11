cmake_minimum_required(VERSION 3.6)
project(Grimwall)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp source/game/Game.cpp source/game/Game.h source/game/EngineFacade.cpp source/game/EngineFacade.h source/game/LevelBuilder.cpp source/game/LevelBuilder.h source/game/UnitFactory.cpp source/game/UnitFactory.h source/game/AUnit.cpp source/game/AUnit.h source/game/IMovable.h source/game/IAbility.h source/game/IVisitable.h source/Gui/GUI.cpp source/Gui/GUI.h source/Gui/IUIComponent.h source/Input/ICallback.h source/Input/KeyboardMapper.cpp source/Input/KeyboardMapper.h source/Input/MouseMapper.cpp source/Input/MouseMapper.h source/Input/MouseCallback.cpp source/Input/MouseCallback.h source/Input/KeypressCallback.cpp source/Input/KeypressCallback.h)
add_executable(Grimwall ${SOURCE_FILES})