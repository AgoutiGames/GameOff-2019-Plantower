#ifndef ENVIRONMENT_HPP_INCLUDED
#define ENVIRONMENT_HPP_INCLUDED

#include "core/game_scene.hpp"

class Environment : public GameScene {
    public:
        Environment(salmon::MapRef map, SceneManager* scene_manager);

        void init() override;
        void update() override;
};

#endif // ENVIRONMENT_HPP_INCLUDED
