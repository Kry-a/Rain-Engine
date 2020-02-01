//
// Created by krasno on 2020-01-31.
//

#include "GameObject.hpp"

GameObject::GameObject() = default;

void GameObject::update() {
    for (auto & script : scripts) {
        script->Update();
    }
}

void GameObject::lateUpdate() {
    for (auto & script : scripts) {
        script->LateUpdate();
    }
}

void GameObject::addScript(GameScript *yes) {
    scripts.push_back(yes);
    yes->gameObject = this;
    yes->Awake();
    yes->Start();
}
