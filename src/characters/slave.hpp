#ifndef SLAVE_HPP_INCLUDED
#define SLAVE_HPP_INCLUDED

#include "core/game_character.hpp"

class GameScene;

class Slave : public GameCharacter {
    public:
        Slave(salmon::ActorRef actor, GameScene* scene);
        virtual Slave* create(salmon::ActorRef actor, GameScene* scene) const override {return new Slave(actor,scene);}

        void init() override;
        void update() override;

        static const char* type;
    protected:
        // Add members here
        
    private:
        static const bool good;
};


#endif // SLAVE_HPP_INCLUDED
