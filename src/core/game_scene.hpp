#ifndef GAME_SCENE_HPP_INCLUDED
#define GAME_SCENE_HPP_INCLUDED

#include <vector>
#include <memory>

#include "map_ref.hpp"
#include "game_character.hpp"

namespace salmon {class GameInfo;}

class GameScene : public salmon::MapRef {
    public:
        GameScene(salmon::MapRef map, salmon::GameInfo* game);
        static GameScene* parse_scene(salmon::MapRef map, salmon::GameInfo* game);

        virtual void init();
        virtual void update();

        bool put(bool& var, std::string name);
        bool put(int& var, std::string name);
        bool put(float& var, std::string name);
        bool put(std::string& var, std::string name);

        void remove_character(GameCharacter* game_character) {m_kill_characters.push_back(game_character);}

        salmon::GameInfo& get_game() {return *m_game;}

    protected:
        salmon::GameInfo* m_game;
        std::vector<std::unique_ptr<GameCharacter>> m_characters;

        std::vector<GameCharacter*> m_kill_characters;
};


#endif // GAME_SCENE_HPP_INCLUDED
