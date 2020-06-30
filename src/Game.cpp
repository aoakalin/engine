//
// Created by aoaka on 30/06/2020.
//

#include "Game.h"
#include <iostream>

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

    this->renderer = SDL_CreateRenderer(this->window, -1, 0);

    if (!this->renderer) {
        std::cerr << "Error creating SDL renderer..." << std::endl;
        return;
    }

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

float renderTestX = 0.0f;
float renderTestXVelocity = 20.0f;
float renderTestY = 0.0f;
float renderTestYVelocity = 30.0f;

void Game::Update() {
    float deltaTime = handleDeltaTime();

    renderTestX += renderTestXVelocity * deltaTime;
    renderTestY += renderTestYVelocity * deltaTime;
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

float renderTestXSize = 10.0f;
float renderTestYSize = 10.0f;

void Game::Render() {
    SDL_SetRenderDrawColor(this->renderer, 21, 21, 21, 255);
    SDL_RenderClear(this->renderer);

    SDL_Rect renderTest{
            (int) renderTestX,
            (int) renderTestY,
            (int) renderTestXSize,
            (int) renderTestYSize
    };
    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(this->renderer, &renderTest);

    SDL_RenderPresent(this->renderer);
}

void Game::Destroy() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}
