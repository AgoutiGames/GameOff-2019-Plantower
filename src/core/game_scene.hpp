#ifndef GAME_SCENE_HPP_INCLUDED
#define GAME_SCENE_HPP_INCLUDED

#include <map>
#include <vector>
#include <memory>
#include <string>

#include "map_ref.hpp"
#include "input_cache_ref.hpp"
#include "core/game_character.hpp"

class SceneManager;

class GameScene : public salmon::MapRef {
    public:
        GameScene(salmon::MapRef map, SceneManager* scene_manager);
        static GameScene* parse_scene(salmon::MapRef map, SceneManager* scene_manager);

        virtual void init();
        virtual void update();
        virtual GameScene* create(salmon::MapRef map, SceneManager* scene_manager) const = 0;

        bool put(bool& var, std::string name);
        bool put(int& var, std::string name);
        bool put(float& var, std::string name);
        bool put(std::string& var, std::string name);

        GameCharacter* get_character_by_name(std::string name);
        GameCharacter* get_character_by_template_type(std::string template_type);
        GameCharacter* get_character_by_attribute(std::string name, bool attribute);
        GameCharacter* get_character_by_attribute(std::string name, int attribute);
        GameCharacter* get_character_by_attribute(std::string name, float attribute);
        GameCharacter* get_character_by_attribute(std::string name, const char* attribute);
        GameCharacter* get_character_by_attribute(std::string name, std::string attribute);
        template <class T>
        T* get_character();

        std::vector<GameCharacter*> get_characters_by_name(std::string name);
        std::vector<GameCharacter*> get_characters_by_template_type(std::string template_type);
        std::vector<GameCharacter*> get_characters_by_attribute(std::string name, bool attribute);
        std::vector<GameCharacter*> get_characters_by_attribute(std::string name, int attribute);
        std::vector<GameCharacter*> get_characters_by_attribute(std::string name, float attribute);
        std::vector<GameCharacter*> get_characters_by_attribute(std::string name, const char* attribute);
        std::vector<GameCharacter*> get_characters_by_attribute(std::string name, std::string attribute);
        template <class T>
        std::vector<T*> get_characters();

        std::vector<GameCharacter*> filter_characters_by_name(std::vector<GameCharacter*> characters, std::string name);
        std::vector<GameCharacter*> filter_characters_by_template_type(std::vector<GameCharacter*> characters, std::string template_type);
        std::vector<GameCharacter*> filter_characters_by_attribute(std::vector<GameCharacter*> characters, std::string name, bool attribute);
        std::vector<GameCharacter*> filter_characters_by_attribute(std::vector<GameCharacter*> characters, std::string name, int attribute);
        std::vector<GameCharacter*> filter_characters_by_attribute(std::vector<GameCharacter*> characters, std::string name, float attribute);
        std::vector<GameCharacter*> filter_characters_by_attribute(std::vector<GameCharacter*> characters, std::string name, const char* attribute);
        std::vector<GameCharacter*> filter_characters_by_attribute(std::vector<GameCharacter*> characters, std::string name, std::string attribute);
        template <class T>
        std::vector<T*> filter_characters(std::vector<GameCharacter*>);

        std::vector<GameCharacter*> get_characters();

        void remove_character(GameCharacter* game_character) {m_kill_characters.push_back(game_character);}

        SceneManager& get_scene_manager() {return *m_scene_manager;}
        salmon::InputCacheRef get_input_cache();

    protected:
        SceneManager* m_scene_manager;
        std::vector<std::unique_ptr<GameCharacter>> m_characters;

        std::vector<GameCharacter*> m_kill_characters;

        template <class T>
        static bool register_class(std::string type);
    private:
        static std::map<std::string, GameScene*>& get_dict();
};

template <class T>
std::vector<T*> GameScene::filter_characters(std::vector<GameCharacter*> characters) {
    std::vector<T*> new_characters;
    for(auto c : characters) {new_characters.push_back(static_cast<T*>(c));}
    return new_characters;
}

template <class T>
std::vector<T*> GameScene::get_characters() {
    std::vector<GameCharacter*> characters = get_characters_by_attribute("type",T::type);
    std::vector<T*> new_characters;
    for(auto c : characters) {new_characters.push_back(static_cast<T*>(c));}
    return new_characters;
}

template <class T>
T* GameScene::get_character() {
    std::vector<T*> characters = get_characters<T>();
    if(characters.empty()) {return nullptr;}
    else {return characters.front();}
}

template <class T>
bool GameScene::register_class(std::string type) {
    MapRef dummy(nullptr);
    GameScene* scene = new T(dummy,nullptr);
    get_dict()[type] = scene;
    return true;
}




#endif // GAME_SCENE_HPP_INCLUDED
