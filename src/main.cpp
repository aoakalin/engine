//
// Created by aoaka on 29/06/2020.
//

#include "Game.h"
#include "Constants.h"
#include <iostream>

int main() {
    std::cout << "Starting VARTS Engine..." << std::endl;

    Game *game = new Game();
    game->Initialize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);

    std::cout << "Initialized VARTS Engine..." << std::endl;

    while (game->IsRunning()) {
        game->ProcessInput();
        game->Update();
        game->Render();
    }

    std::cout << "Shutting down VARTS Engine..." << std::endl;

    game->Destroy();

    std::cout << "Stopped VARTS Engine..." << std::endl;

    return 0;
}
