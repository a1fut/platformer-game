#Plik CMakeList.txt został wygenerowany chatem gpt
#z racji, że operuję na systemie macOS i nie mogłem znaleźć żadnego działającego w internecie
#który by działał i na windowsie i na macu
cmake_minimum_required(VERSION 3.26)
project(SFMLtest)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)


FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.0
)
include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG        10.0.0
)

FetchContent_MakeAvailable(fmt)

FetchContent_GetProperties(SFML)

if(NOT SFML_POPULATED)
    FetchContent_Populate(SFML)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

add_executable(SFMLtest main.cpp
        Game/Game.cpp
        Game/Game.hpp
        Player/Player.cpp
        Player/Player.hpp
        Maps/Maps.cpp
        Maps/Maps.hpp
        Maps/MapOne/mapOne.cpp
        Maps/MapOne/mapOne.hpp
        Maps/defaultMap.cpp
        Maps/defaultMap.hpp
        Maps/MapTwo/mapTwo.cpp
        Maps/MapTwo/mapTwo.hpp
        Player/TextureLoader.cpp
        Player/TextureLoader.hpp
        Player/Bullet.cpp
        Player/Bullet.hpp
        Maps/Enemies/MirrorEnemy.cpp
        Maps/Enemies/MirrorEnemy.hpp
        Maps/Enemies/WalkingEnemy.cpp
        Maps/Enemies/WalkingEnemy.hpp
        Maps/Enemies/Enemy.cpp
        Maps/Enemies/Enemy.hpp
        Maps/Key.cpp
        Maps/Key.hpp
        Maps/Portal.cpp
        Maps/Portal.hpp
        Maps/Enemies/GhostEnemy.cpp
        Maps/Enemies/GhostEnemy.hpp
        Maps/MapThree/mapThree.cpp
        Maps/MapThree/mapThree.hpp
        Maps/itemRoom.cpp
        Maps/itemRoom.hpp
        Maps/Items.cpp
        Maps/Items.hpp

)

# Dołączanie bibliotek SFML
#target_link_libraries(SFMLtest fmt)
target_include_directories(SFMLtest PRIVATE ${SFML_SOURCE_DIR}/include)
target_link_libraries(SFMLtest PRIVATE sfml-system sfml-window sfml-graphics sfml-network sfml-audio fmt)
