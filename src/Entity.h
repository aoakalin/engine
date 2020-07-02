//
// Created by aoaka on 02/07/2020.
//

#ifndef ENGINE_ENTITY_H
#define ENGINE_ENTITY_H

#include "Component.h"
#include <string>
#include <vector>

class EntityManager;

class Component;

class Entity {
private:
    EntityManager &manager;
    bool isActive;
    std::vector<Component *> components;
public:
    std::string name;

    Entity(EntityManager &manager);

    Entity(EntityManager &manager, std::string name);

    void Update(float deltaTime);

    void Render();

    void Destroy();

    bool IsActive() const;

    template <typename T, typename... TArgs>
    T& AddComponent(TArgs&&... args) {
        T* newComponent(new T(std::forward<TArgs>(args)...));
        newComponent->owner = this;
        components.emplace_back(newComponent);
        newComponent->Initialize();
        return *newComponent;
    }
};


#endif //ENGINE_ENTITY_H
