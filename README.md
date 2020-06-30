# engine

I am trying to create my own games using various game engines like Unity, Unreal, Godot, Phaser, Babylon.js. However, everytime I make a prototype, I am hitting to a wall or wasting a lot of time because I lack the basic knowledge/experience regarding low level technologies behind games & game engines.

The aim of this project is to go back to basics and get my hands dirty by creating my own game engine using the good old C++. I don't plan on making this a full blown project, just a quick and dirty one to get the hang of things, so that I can move forward with other serious projects.

# dependencies

The project is using mingw64 for builds: (http://win-builds.org/1.5.0/win-builds-1.5.0.exe)

CMakeLists.txt contains every dependency information, however, as a high level summary:

* SDL2-devel-2.0.12-mingw.tar.gz (https://www.libsdl.org/release/SDL2-2.0.12-win32-x64.zip)
* SDL2_image-devel-2.0.5-mingw.tar.gz (https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.5-mingw.tar.gz)
* SDL2_ttf-devel-2.0.15-mingw.tar.gz (https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.15-mingw.tar.gz)
* SDL2_mixer-devel-2.0.4-mingw.tar.gz (https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-devel-2.0.4-mingw.tar.gz)
* glm-0.9.9.8.zip (https://github.com/g-truc/glm/releases/download/0.9.9.8/glm-0.9.9.8.zip)
* lua-5.3.5_Win64_dllw6_lib.zip (https://sourceforge.net/projects/luabinaries/files/5.3.5/Windows%20Libraries/Dynamic/lua-5.3.5_Win64_dllw6_lib.zip/download)

Contents of those files must be placed on a folder called lib at the project root level. The folder structure for lib is shown below:

```
lib
│
└───lua-5.3.5_Win64_dllw6_lib
│   │   liblua53.a
│   │   lua53.dll
│   │
│   └───include
│       │   ...
│   
└───SDL2-x86_64-w64-mingw32
│   └───bin
│   │   │   ...
│   │   
│   └───include
│   │   │   ...
│   │   
│   └───lib
│   │   │   ...
│   │   
│   └───share
│   │   │   ...
│   
└───glm
│   │   CMakeLists.txt
│   │   common.hpp
│   │   ...
│   │
│   └───detail
│   │   │   ...
│   └───ext
│   │   │   ...
│   └───gtc
│   │   │   ...
│   └───gtx
│   │   │   ...
│   └───simd
│   │   │   ...
```
