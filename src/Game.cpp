//
// Created by aoaka on 30/06/2020.
//

#include "Game.h"
#include "glm.hpp"
#include "EntityManager.h"
#include "Components/TransformComponent.h"
#include <iostream>

EntityManager manager;
SDL_Renderer *Game::renderer;

Game::Game() {
    this->isRunning = false;
}

Game::~Game() = default;

void Game::Initialize(unsigned int width, unsigned int height, unsigned int frameTargetTime) {
    this->width = width;
    this->height = height;
    this->frameTargetTime = frameTargetTime;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL..." << std::endl;
        return;
    }

    this->window = SDL_CreateWindow(nullptr, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
                                    SDL_WINDOW_BORDERLESS);

    if (!this->window) {
        std::cerr << "Error creating SDL window..." << std::endl;
        return;
    }

    Game::renderer = SDL_CreateRenderer(this->window, -1, 0);

    if (!Game::renderer) {
        std::cerr << "Error creating SDL renderer..." << std::endl;
        return;
    }

    LoadLevel(0);

    this->isRunning = true;
}

bool Game::IsRunning() const {
    return this->isRunning;
}

void Game::ProcessInput() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            this->isRunning = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                this->isRunning = false;
            }
            break;
        default:
            break;
    }
}

void Game::Update() {
    float deltaTime = handleDeltaTime();
    manager.Update(deltaTime);
}

float Game::handleDeltaTime() {
    unsigned int timeToWait = frameTargetTime - (SDL_GetTicks() - ticksLastFrame);
    if (timeToWait > 0 && timeToWait <= frameTargetTime) {
        SDL_Delay(timeToWait);
    }
//    while (!SDL_TICKS_PASSED(SDL_GetTicks(), this->ticksLastFrame + this->frameTargetTime));

    Uint32 ticks = SDL_GetTicks();
    float deltaTime = (ticks - this->ticksLastFrame) / 1000.0f;
    deltaTime = (deltaTime > this->frameTargetTime) ? this->frameTargetTime : deltaTime;
    this->ticksLastFrame = ticks;
    return deltaTime;
}

void Game::Render() {
    SDL_SetRenderDrawColor(this->renderer, 21, 21, 21, 255);
    SDL_RenderClear(this->renderer);

    if (manager.HasNoEntities()) {
        return;
    }
    manager.Render();

    SDL_RenderPresent(this->renderer);
}

void Game::Destroy() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void Game::LoadLevel(int levelNumber) {
    //todo implement later
    Entity &newEntity(manager.AddEntity("test"));
    newEntity.AddComponent<TransformComponent>(0, 0, 20, 20, 32, 32, 1);
}
