#ifndef GAME_SCENE_HPP_INCLUDED
#define GAME_SCENE_HPP_INCLUDED

#include <vector>
#include <memory>

#include "map_ref.hpp"
#include "game_character.hpp"

namespace salmon {class GameInfo;}
class SceneManager;

class GameScene : public salmon::MapRef {
    public:
        GameScene(salmon::MapRef map, salmon::GameInfo* game, SceneManager* scene_manager);
        static GameScene* parse_scene(salmon::MapRef map, salmon::GameInfo* game, SceneManager* scene_manager);

        virtual void init();
        virtual void update();

        bool put(bool& var, std::string name);
        bool put(int& var, std::string name);
        bool put(float& var, std::string name);
        bool put(std::string& var, std::string name);

        GameCharacter& get_character_by_name(std::string name);
        GameCharacter& get_character_by_template_type(std::string template_type);
        GameCharacter& get_character_by_attribute(std::string name, bool attribute);
        GameCharacter& get_character_by_attribute(std::string name, int attribute);
        GameCharacter& get_character_by_attribute(std::string name, float attribute);
        GameCharacter& get_character_by_attribute(std::string name, std::string attribute);

        std::vector<GameCharacter*> get_characters_by_name(std::string name);
        std::vector<GameCharacter*> get_characters_by_template_type(std::string template_type);
        std::vector<GameCharacter*> get_characters_by_attribute(std::string name, bool attribute);
        std::vector<GameCharacter*> get_characters_by_attribute(std::string name, int attribute);
        std::vector<GameCharacter*> get_characters_by_attribute(std::string name, float attribute);
        std::vector<GameCharacter*> get_characters_by_attribute(std::string name, std::string attribute);

        void remove_character(GameCharacter* game_character) {m_kill_characters.push_back(game_character);}

        salmon::GameInfo& get_game() {return *m_game;}
        SceneManager& get_scene_manager() {return *m_scene_manager;}

    protected:
        salmon::GameInfo* m_game;
        SceneManager* m_scene_manager;
        std::vector<std::unique_ptr<GameCharacter>> m_characters;

        std::vector<GameCharacter*> m_kill_characters;
};


#endif // GAME_SCENE_HPP_INCLUDED
