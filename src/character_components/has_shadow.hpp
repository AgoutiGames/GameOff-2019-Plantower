#ifndef HAS_SHADOW_HPP_INCLUDED
#define HAS_SHADOW_HPP_INCLUDED

#include "core/game_character.hpp"

class HasShadow : public virtual GameCharacter {
    public:

    protected:
        // Functions and members aren't protected to game characters
        // who also inherit from this component!
        bool init_shadow(std::string character_template_name, std::string layer_name, float x_offset, float y_offset);
        void update_shadow();
        GameCharacter* get_shadow();
        void tweak_shadow_position();
        virtual ~HasShadow();

    private:
        GameCharacter* m_shadow = nullptr;
        float m_x_offset = 0;
        float m_y_offset = 0;
};


#endif // HAS_SHADOW_HPP_INCLUDED
