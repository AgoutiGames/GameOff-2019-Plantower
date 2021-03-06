#ifndef SMALL_ENEMY_HPP_INCLUDED
#define SMALL_ENEMY_HPP_INCLUDED

#include "core/game_character.hpp"

#include "characters/marker.hpp"

class GameScene;

class SmallEnemy : public virtual GameCharacter {
    public:
        SmallEnemy(salmon::ActorRef actor, GameScene* scene);
        virtual SmallEnemy* create(salmon::ActorRef actor, GameScene* scene) const override {return new SmallEnemy(actor,scene);}

        void init() override;
        void update() override;
        std::string get_type() const override {return type;}

        bool move(float x, float y) {return move_relative(x,y,salmon::Collidees::tile,{salmon::DEFAULT_HITBOX},{salmon::DEFAULT_HITBOX},false);}

        static const char* type;
    protected:
        // Add members here
        float m_base_speed = 250;
        std::vector<Marker*> m_markers;
        unsigned m_current_marker = 0;

    private:
        static const bool good;
};


#endif // SMALL_ENEMY_HPP_INCLUDED
