//
// Created by aoaka on 02/07/2020.
//

#ifndef ENGINE_ENTITYMANAGER_H
#define ENGINE_ENTITYMANAGER_H

#include "./Entity.h"
#include "./Component.h"
#include <string>
#include <vector>

class EntityManager {
private:
    std::vector<Entity *> entities;
public:
    void ClearData();

    void Update(float deltaTime);

    void Render();

    bool HasNoEntities();

    Entity &AddEntity(std::string entityName);

    std::vector<Entity *> GetEntities() const;

    unsigned long long int GetEntityCount();
};


#endif //ENGINE_ENTITYMANAGER_H
