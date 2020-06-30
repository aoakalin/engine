//
// Created by aoaka on 30/06/2020.
//

#include "Game.h"
#include "Constants.h"
#include <iostream>

Game::Game() {
    this->isRunning = false;
}

Game::~Game() {

}

void Game::Initialize(int width, int height) {
    this->width = width;
    this->height = height;
    this->isRunning = true;
}

bool Game::IsRunning() const {
    return this->isRunning;
}

void Game::ProcessInput() {

}

void Game::Update() {

}

void Game::Render() {

}

void Game::Destroy() {

}
