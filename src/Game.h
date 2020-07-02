//
// Created by aoaka on 30/06/2020.
//

#ifndef ENGINE_GAME_H
#define ENGINE_GAME_H

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

class Game {
private:
    SDL_Window *window;
    bool isRunning;
    unsigned int width;
    unsigned int height;
    unsigned int frameTargetTime;
    unsigned int ticksLastFrame;

public:
    Game();

    ~Game();

    void Initialize(unsigned int width, unsigned int height, unsigned int frameTargetTime);

    bool IsRunning() const;

    static SDL_Renderer *renderer;

    void LoadLevel(int levelNumber);

    void ProcessInput();

    void Update();

    void Render();

    void Destroy();

    float handleDeltaTime();
};


#endif //ENGINE_GAME_H
