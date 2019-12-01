#ifndef SMALL_ENEMY_ALT_HPP_INCLUDED
#define SMALL_ENEMY_ALT_HPP_INCLUDED

#include "core/game_character.hpp"
#include "characters/small_enemy.hpp"
#include "character_components/has_shadow.hpp"

class GameScene;

class SmallEnemyAlt : public SmallEnemy, HasShadow {
    public:
        SmallEnemyAlt(salmon::ActorRef actor, GameScene* scene);
        virtual SmallEnemyAlt* create(salmon::ActorRef actor, GameScene* scene) const override {return new SmallEnemyAlt(actor,scene);}

        void init() override;
        void update() override;

        static const char* type;
    protected:
        // Add members here

    private:
        static const bool good;
};


#endif // SMALL_ENEMY_ALT_HPP_INCLUDED
