#ifndef GAME_CHARACTER_HPP_INCLUDED
#define GAME_CHARACTER_HPP_INCLUDED

#include "actor_ref.hpp"

class GameScene;

class GameCharacter : public salmon::ActorRef {
    public:
        GameCharacter(salmon::ActorRef actor, GameScene* scene);
        static GameCharacter* parse_character(salmon::ActorRef actor, GameScene* scene);

        virtual void init() = 0;
        virtual void update() = 0;

        bool put(bool& var, std::string name);
        bool put(int& var, std::string name);
        bool put(float& var, std::string name);
        bool put(std::string& var, std::string name);

    protected:
        GameScene* m_scene;
};

#endif // GAME_CHARACTER_HPP_INCLUDED
