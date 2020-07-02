cmake_minimum_required(VERSION 3.13)

project(engine)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp src/Game.cpp src/Game.h src/Constants.h src/Component.h src/Entity.cpp src/Entity.h src/EntityManager.cpp src/EntityManager.h src/Components/TransformComponent.cpp src/Components/TransformComponent.h)

#set(SDL2_INCLUDE_DIR lib/SDL2-x86_64-w64-mingw32/include/SDL2)
#set(SDL2_LIB_DIR lib/SDL2-x86_64-w64-mingw32/lib)

set(LUA_INCLUDE_DIR lib/lua-5.3.5_Win64_dllw6_lib/include)
set(LUA_LIB_DIR lib/lua-5.3.5_Win64_dllw6_lib)

set(GLM_INCLUDE_DIR lib/glm)

#include_directories(${SDL2_INCLUDE_DIR} ${LUA_INCLUDE_DIR} ${GLM_INCLUDE_DIR})
include_directories(${LUA_INCLUDE_DIR} ${GLM_INCLUDE_DIR})
#link_directories(${SDL2_LIB_DIR} ${LUA_LIB_DIR})
link_directories(${LUA_LIB_DIR})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
#target_link_libraries(${PROJECT_NAME} mingw32 SDL2main SDL2_image SDL2_ttf SDL2_mixer SDL2 lua53)
target_link_libraries(${PROJECT_NAME} mingw32 SDL2main SDL2 lua53)
