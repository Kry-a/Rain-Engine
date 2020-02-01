//
// Created by krasno on 2020-01-31.
//

#ifndef RAIN_ENGINE_GAMESCRIPT_HPP
#define RAIN_ENGINE_GAMESCRIPT_HPP


#include "GameObject.hpp"

class GameObject;

class GameScript {
public:
    GameObject *gameObject;
public:
    GameScript();
    virtual void Awake() = 0;
    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void LateUpdate() = 0;
};


#endif //RAIN_ENGINE_GAMESCRIPT_HPP
