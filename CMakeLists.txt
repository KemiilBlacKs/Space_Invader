cmake_minimum_required(VERSION 3.2)
project(Space_Invaders)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES
        Main.cpp
        Source/Game.cpp
        Source/World.cpp
        Source/StarsBackground.cpp
        Source/AnimationRenderer.cpp
        Source/ManagerInvader.cpp
        Entity/Player.cpp
        Entity/Invader.cpp
        Entity/Explosion.cpp
        Entity/Projectile.cpp
        Entity/Collidable.cpp
        Entity/Shield.cpp
        Entity/UFO.cpp
        Utils/Animation.cpp
        Utils/StateBase.cpp
        Utils/NonCopyable.hh
        Utils/FpsCounter.cpp
        Utils/NonMoveable.hh
        Utils/ResourceHolder.cpp
        Utils/ResourceManager.hh
        Utils/StateHighscores.cpp
        Utils/StateMainMenu.cpp
        Utils/Random.hh
        Utils/DisplayInfo.hh
        Utils/StatePlaying.cpp
        GUI/StackMenu.cpp
        GUI/StackMenu.hh
        GUI/Widget.cpp
        GUI/Button.cpp
        GUI/Textbox.cpp)
add_executable(Space_Invaders ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Space_Invaders ${SFML_LIBRARIES})
endif ()
