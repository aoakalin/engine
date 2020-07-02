#include <utility>

#include <utility>

#include <utility>

//
// Created by aoaka on 02/07/2020.
//

#include "EntityManager.h"

void EntityManager::ClearData() {
    for (auto &entity: entities) {
        entity->Destroy();
    }
}

void EntityManager::Update(float deltaTime) {
    for (auto &entity: entities) {
        entity->Update(deltaTime);
    }
}

void EntityManager::Render() {
    for (auto &entity: entities) {
        entity->Render();
    }
}

bool EntityManager::HasNoEntities() {
    return this->entities.empty();
}

Entity &EntityManager::AddEntity(std::string entityName) {
    auto *entity = new Entity(*this, std::move(entityName));
    entities.emplace_back(entity);
    return *entity;
}

std::vector<Entity *> EntityManager::GetEntities() const {
    return this->entities;
}

unsigned long long int EntityManager::GetEntityCount() {
    return this->entities.size();
}
