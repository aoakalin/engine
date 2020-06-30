# engine

I am trying to create my own games using various game engines like Unity, Unreal, Godot, Phaser, Babylon.js. However, everytime I make a prototype, I am hitting to a wall or wasting a lot of time because I lack the basic knowledge/experience regarding low level technologies behind games & game engines.

The aim of this project is to go back to basics and get my hands dirty by creating my own game engine using the good old C++. I don't plan on making this a full blown project, just a quick and dirty one to get the hang of things, so that I can move forward with other serious projects.

# dependencies

CMakeLists.txt contains every information, however, as a high level summary:
  SDL2-devel-2.0.12-mingw.tar.gz
  SDL2_image-devel-2.0.5-mingw.tar.gz
  SDL2_ttf-devel-2.0.15-mingw.tar.gz
  SDL2_mixer-devel-2.0.4-mingw.tar.gz
  lua-5.3.5_Win64_dllw6_lib.zip

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
```
