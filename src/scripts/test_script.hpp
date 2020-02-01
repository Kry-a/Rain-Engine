//
// Created by krasno on 2020-01-31.
//

#ifndef RAIN_ENGINE_TEST_SCRIPT_HPP
#define RAIN_ENGINE_TEST_SCRIPT_HPP


#include "../engine/GameScript.hpp"

class test_script : public GameScript {
    void Awake() override;
    void Start() override;
    void Update() override;
    void LateUpdate() override;
};


#endif //RAIN_ENGINE_TEST_SCRIPT_HPP
