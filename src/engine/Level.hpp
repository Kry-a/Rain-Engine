//
// Created by krasno on 2020-02-01.
//

#ifndef RAIN_ENGINE_LEVEL_HPP
#define RAIN_ENGINE_LEVEL_HPP


#include <vector>
#include "GameObject.hpp"

class GameObject;

class Level {
public:
    std::vector<GameObject> objects;
};


#endif //RAIN_ENGINE_LEVEL_HPP
