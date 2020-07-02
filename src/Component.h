//
// Created by aoaka on 02/07/2020.
//

#ifndef ENGINE_COMPONENT_H
#define ENGINE_COMPONENT_H

class Entity;

class Component {
public:
    Entity *owner;

    virtual ~Component() {};

    virtual void Initialize() {};

    virtual void Update(float deltaTime) {};

    virtual void Render() {};
};


#endif //ENGINE_COMPONENT_H
