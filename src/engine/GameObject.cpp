//
// Created by krasno on 2020-01-31.
//

#include "GameObject.hpp"

GameObject::GameObject() {
    for (auto & script : scripts) {
        script.Awake();
    }

    for (auto & script : scripts) {
        script.Start();
    }
}
