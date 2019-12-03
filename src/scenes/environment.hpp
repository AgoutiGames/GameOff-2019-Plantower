#ifndef ENVIRONMENT_HPP_INCLUDED
#define ENVIRONMENT_HPP_INCLUDED

#include "core/game_scene.hpp"

class Environment : public GameScene {
    public:
        Environment(salmon::MapRef map, SceneManager* scene_manager);
        Environment* create(salmon::MapRef map, SceneManager* scene_manager) const override {return new Environment(map,scene_manager);}

        void init() override;
        void update() override;

        static const char* type;
    protected:
        std::vector<GameCharacter*> m_small_enemies;

        bool m_fullscreen = false;

        float m_zoom_level = 1.2f;

        static float enemy_cooldown;
        float m_current_enemy_cooldown = 0;
    private:
        static const bool good;
};

#endif // ENVIRONMENT_HPP_INCLUDED
