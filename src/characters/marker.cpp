#include "characters/marker.hpp"

const char* Marker::type = "Marker";
const bool Marker::good = GameCharacter::register_class<Marker>(Marker::type);

Marker::Marker(salmon::ActorRef actor, GameScene* scene) : GameCharacter(actor, scene) {}

void Marker::init() {
    // Setup member vars here | example: put(m_speed, "m_speed");
    put(m_center, "center");
    put(m_x_offset, "x_offset");
    put(m_y_offset, "y_offset");
    bool hide = false;
    put(hide, "hide");
    if(hide) {set_hidden(true);}
}

void Marker::update() {
    // Add character logic here

}

float Marker::get_marker_pos_x() {
    return m_x_offset + get_x_center();
}
float Marker::get_marker_pos_y() {
    return m_y_offset + get_y_center();
}
