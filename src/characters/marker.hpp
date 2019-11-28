#ifndef MARKER_HPP_INCLUDED
#define MARKER_HPP_INCLUDED

#include "core/game_character.hpp"

class GameScene;

class Marker : public GameCharacter {
    public:
        Marker(salmon::ActorRef actor, GameScene* scene);
        virtual Marker* create(salmon::ActorRef actor, GameScene* scene) const override {return new Marker(actor,scene);}

        void init() override;
        void update() override;

        float get_marker_pos_x();
        float get_marker_pos_y();

        static const char* type;
    protected:
        // Add members here
        bool m_center = true;
        float m_x_offset = 0;
        float m_y_offset = 0;

    private:
        static const bool good;
};


#endif // MARKER_HPP_INCLUDED
