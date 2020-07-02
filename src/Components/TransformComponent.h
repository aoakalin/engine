//
// Created by aoaka on 02/07/2020.
//

#ifndef ENGINE_TRANSFORMCOMPONENT_H
#define ENGINE_TRANSFORMCOMPONENT_H

#include <SDL2/SDL.h>
#include "../EntityManager.h"
#include "glm.hpp"
#include "../Game.h"

class TransformComponent : public Component {
public:
    glm::vec2 position;
    glm::vec2 velocity;
    int width;
    int height;
    int scale;

    TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s) {
        position = glm::vec2(posX, posY);
        velocity = glm::vec2(velX, velY);
        width = w;
        height = h;
        scale = s;
    }

    ~TransformComponent() override {

    }

    void Initialize() override {
        Component::Initialize();
    }

    void Update(float deltaTime) override {
        Component::Update(deltaTime);

        position.x += velocity.x * deltaTime;
        position.y += velocity.y * deltaTime;
    }

    void Render() override {
        Component::Render();

        SDL_Rect transformRectangle = {
                (int) position.x,
                (int) position.y,
                width,
                height
        };

        SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(Game::renderer, &transformRectangle);
    }
};


#endif //ENGINE_TRANSFORMCOMPONENT_H
