cmake_minimum_required(VERSION 3.6)
project(Grimwall)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp source/game/Game.cpp source/game/Game.h source/game/EngineFacade.cpp source/game/EngineFacade.h source/game/LevelBuilder.cpp source/game/LevelBuilder.h source/game/UnitFactory.cpp source/game/UnitFactory.h source/game/AUnit.cpp source/game/AUnit.h source/game/IMovable.h source/game/IAbility.h source/game/IVisitable.h source/gui/GUI.cpp source/gui/GUI.h source/gui/IUIComponent.h source/input/ICallback.h source/input/KeyboardMapper.cpp source/input/KeyboardMapper.h source/input/MouseMapper.cpp source/input/MouseMapper.h source/input/MouseCallback.cpp source/input/MouseCallback.h source/input/KeypressCallback.cpp source/input/KeypressCallback.h)
add_executable(Grimwall ${SOURCE_FILES})