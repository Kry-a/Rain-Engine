//
// Created by krasno on 2020-01-31.
//

#ifndef RAIN_ENGINE_GAMEOBJECT_HPP
#define RAIN_ENGINE_GAMEOBJECT_HPP


#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <vector>
#include "GameScript.hpp"

using namespace glm;

class GameObject {
public:
    vec3 position{.x = 0, .y = 0, .z = 0};
    quat rotation{.w = 0, .x = 0, .y = 0, .z = 0};
    vec3 scale{.x = 1, .y = 1, .z = 1};
    std::vector<GameScript> scripts;
public:
    GameObject();
};


#endif //RAIN_ENGINE_GAMEOBJECT_HPP
