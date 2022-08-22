#ifndef _SQUAD_HPP
#define _SQUAD_HPP

#include <string>
#include "monster.hpp"

/**
 * @brief A class implementing a squad of monsters and/or squad of squads.
 */
class Squad {
protected:

    /**
     * @brief Dynamically allocated array of squads.
     */
    Squad **squads;

    /**
     * @brief Number of sub-squads in this squad.
     */
    int squad_count;

    /**
     * @brief Dynamically allocated array of monsters.
     */
    Monster **monsters;

    /**
     * @brief Number of monsters in this squad. Monsters from sub-squads are
     * not counted here.
     */
    int monster_count;

    /**
     * @brief Number of all monsters in this squad and all sub-squads.
     */
    int total_monster_count;

public:

    /**
     * @brief Constructor. Creates monsters and stores them in the
     * <b>monsters</b> array. It parses the <b>input</b>
     * instructions to know which monsters to create.
     * @param input A string with all-lower-case names of monsters
     * ("crazy", "dangerous", "crazydangerous") separated
     * by commas (,). No whitespace allowed. It is assumed, that the input
     * is correct. Empty input is correct and is allowed. Examples:
     * "crazy,crazy"
     * "crazy,crazydangerous,dangerous"
     * ""
     */
    Squad(const std::string &input);

    /**
     * @brief Destructor. Frees memory of arrays to store pointers to the
     * squads and to the monsters. It also frees the memory of all monsters
     * and sud-squads.
     */
    ~Squad();

    /**
     * @brief Returns the number of monsters in the squad and all
     * sub-squads that are CrazyMonsters (or inherit from CrazyMonster class).
     * @return Number of crazy monsters.
     */
    int crazyCount() const;

    /**
     * @brief Orders to attack the monster with the given index.
     * Monsters are indexed from 0. First the monsters directly in this team
     * are counted, then the monsters from sub-teams in order of their
     * recruitment.
     * @param index Index of the monster to order to attack. In PART 2 if the
     * index is out of bounds do nothing. In PART 3 if the index is out of
     * bounds throw an exception.
     */
    void attack(int index) const;
    /**
     * @brief Adds a sub-squad to this squad. The new sub-squad is added at the
     * end of the list/array of the previously added sub-squads.
     * @param other_squad Pointer to the squad to be added as a sub-squad of
     * this squad.
     */
    void recruit(Squad *other_squad);
};

#endif
