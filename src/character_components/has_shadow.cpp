#include "character_components/has_shadow.hpp"

#include <iostream>

#include "core/game_scene.hpp"

HasShadow::~HasShadow() {
    if(m_shadow != nullptr) {
        m_scene->remove_character(m_shadow);
    }
}

bool HasShadow::init_shadow(std::string character_template_name, std::string layer_name, float x_offset, float y_offset) {
    m_shadow = m_scene->add_character(character_template_name,layer_name, get_name()+"Shadow");
    m_x_offset = x_offset;
    m_y_offset = y_offset;
    return m_shadow != nullptr;
}
void HasShadow::update_shadow() {
    m_shadow->set_animation(get_animation(),get_direction(),get_current_anim_frame());
    m_shadow->move_absolute(get_x()+m_x_offset,get_y()+m_y_offset);
}
GameCharacter* HasShadow::get_shadow() {
    return m_shadow;
}
void HasShadow::tweak_shadow_position() {
    salmon::InputCacheRef input = m_scene->get_input_cache();
    if(input.just_pressed("Up")) {
        m_y_offset--;
    }
    else if(input.just_pressed("Down")) {
        m_y_offset++;
    }
    else if(input.just_pressed("Left")) {
        m_x_offset--;
    }
    else if(input.just_pressed("Right")) {
        m_x_offset++;
    }
    else {return;}
    std::cout << "Shadow x offset: " << m_x_offset << " y offset: " << m_y_offset << "\n";
}
