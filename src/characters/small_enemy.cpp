#include "characters/small_enemy.hpp"

#include <string>
#include <sstream>
#include <iostream>
#include <cmath>

#include "core/game_scene.hpp"

const char* SmallEnemy::type = "SmallEnemy";
const bool SmallEnemy::good = GameCharacter::register_class<SmallEnemy>(SmallEnemy::type);

SmallEnemy::SmallEnemy(salmon::ActorRef actor, GameScene* scene) : GameCharacter(actor, scene) {}

void SmallEnemy::init() {
    // Setup member vars here | example: put(m_speed, "m_speed");
    put(m_base_speed, "base_speed");
    std::string marker_var_name = "checkpoint";
    std::stringstream current_marker_var_name;
    std::string checkpoint_name;
    for(int i = 1; ;i++) {
        current_marker_var_name << marker_var_name << i;
        put(checkpoint_name, current_marker_var_name.str());
        if(checkpoint_name == "") {break;}
        GameCharacter* checkpoint = m_scene->get_character_by_name(checkpoint_name);
        if(checkpoint == nullptr) {
            std::cerr << "There is no character called: " << checkpoint_name << "\n";
        }
        else if(checkpoint->get_data().get_val_string("type") != "Marker") {
            std::cerr << "Character called: " << checkpoint_name << " is not of type Marker\n";
        }
        else {
            m_markers.push_back(static_cast<Marker*>(checkpoint));
        }
    }
}

void SmallEnemy::update() {
    if(m_current_marker < m_markers.size()) {
        constexpr float checkpoint_threshold = 50;
        // Add character logic here
        Marker* marker = m_markers[m_current_marker];
        float x_distance = marker->get_marker_pos_x()-get_x_center();
        float y_distance = marker->get_marker_pos_y()-get_y_center();

        float radians = std::atan2(x_distance,y_distance);
        float delta = m_scene->get_delta_time();

        move(std::cos(radians)*m_base_speed*delta, std::sin(radians)*m_base_speed*delta);

        if(x_distance < checkpoint_threshold && y_distance < checkpoint_threshold) {
            m_current_marker++;
        }
    }
}
