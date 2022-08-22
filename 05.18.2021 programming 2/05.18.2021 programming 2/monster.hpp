#ifndef _MONSTER_HPP
#define _MONSTER_HPP

class Monster {
public:
    virtual ~Monster() = default;
    virtual void attack() const = 0;
};

#endif
