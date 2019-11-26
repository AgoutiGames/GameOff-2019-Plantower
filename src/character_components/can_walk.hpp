#ifndef CANWALK_HPP_INCLUDED
#define CANWALK_HPP_INCLUDED

#include "core/game_character.hpp"

class CanWalk : public virtual GameCharacter {
    public:

    protected:
        // Functions and members aren't protected to game characters
        // who also inherit from this component!
        bool walk(salmon::Direction dir, float walk_speed = 1.0f, float animation_speed = 1.0f);
    private:

};


#endif // CANWALK_HPP_INCLUDED
