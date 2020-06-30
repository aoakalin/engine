//
// Created by aoaka on 29/06/2020.
//

#include "Game.h"
#include "Constants.h"
#include <iostream>

int main(int argv, char** args) {
    std::cout << "Starting VARTS Engine..." << std::endl;

    auto game = new Game();
    game->Initialize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);

    while (game->IsRunning()) {
        game->ProcessInput();
        game->Update();
        game->Render();
    }

    game->Destroy();

    std::cout << "Stopped VARTS Engine..." << std::endl;

    return 0;
}
