#ifndef TOWER_HPP_INCLUDED
#define TOWER_HPP_INCLUDED

#include "core/game_character.hpp"

class GameScene;

class Tower : public GameCharacter {
    public:
        Tower(salmon::ActorRef actor, GameScene* scene);
        virtual Tower* create(salmon::ActorRef actor, GameScene* scene) const override {return new Tower(actor,scene);}

        void init() override;
        void update() override;

        void power_up();

        static const char* type;
    protected:
        // Add members here
        static constexpr float firing_distance = 400; // Pixels
        static constexpr float cooldown = 0.8; // Seconds
        float m_current_cooldown = 0;


    private:
        enum {
            inactive,
            powering_up,
            active,
        } m_state = inactive;
        static const bool good;
};


#endif // TOWER_HPP_INCLUDED
