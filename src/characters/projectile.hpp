#ifndef PROJECTILE_HPP_INCLUDED
#define PROJECTILE_HPP_INCLUDED

#include "core/game_character.hpp"

class GameScene;

class Projectile : public GameCharacter {
    public:
        Projectile(salmon::ActorRef actor, GameScene* scene);
        virtual Projectile* create(salmon::ActorRef actor, GameScene* scene) const override {return new Projectile(actor,scene);}

        void init() override;
        void update() override;
        std::string get_type() const override {return type;}

        void move(float x, float y) {return move_relative(x,y);}
        void set_target(GameCharacter* character);

        static const char* type;
    protected:
        // Add members here
        GameCharacter* m_target = nullptr;

        float m_speed = 500;

    private:
        static const bool good;
};


#endif // PROJECTILE_HPP_INCLUDED
