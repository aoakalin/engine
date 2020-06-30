//
// Created by aoaka on 30/06/2020.
//

#ifndef ENGINE_GAME_H
#define ENGINE_GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

class Game {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool isRunning;
    int width;
    int height;

public:
    Game();

    ~Game();
    
    void Initialize(int width, int height);

    bool IsRunning() const;

    void ProcessInput();

    void Update();

    void Render();

    void Destroy();
};


#endif //ENGINE_GAME_H
