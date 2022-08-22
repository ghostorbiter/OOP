#include <iostream>
#include "monster.hpp"
#include "crazy_monster.hpp"
#include "dangerous_monster.hpp"
#include "crazy_dangerous_monster.hpp"
#include "squad.hpp"



int main()
{
    // part 1 (2,5p)
    Monster* monsters[3];
    monsters[0] = new CrazyMonster();
    monsters[1] = new DangerousMonster();
    monsters[2] = new CrazyDangerousMonster();
    for (auto monster : monsters) {
        monster->attack();
    }
    for (auto monster : monsters) {
        delete monster;
    }
    std::cout << std::endl;

    // part 2a (2,5p)
    auto crazy_monsters = new Squad("crazy,crazy,crazy,crazy");

    Squad team("crazydangerous");
    team.attack(0);
    std::cout << std::endl;

    // part 2b (2p)
    team.recruit(crazy_monsters);
    team.recruit(new Squad("crazy,dangerous,crazydangerous"));

    std::cout << "Number of crazy monsters in a team: "
        << team.crazyCount() << std::endl;

    team.attack(2);
    team.attack(6);

    // part 3 (1p)
    //TODO: add try - catch around all attack() calls.
    /*try {
        team.attack(88);
    }
    catch (const char* e)
    {
        cout << "Exception: " << e << endl;
    }

    return 0;*/
}

/*
Example output:

Crazy monster attacks!
Dangerous monster attacks!
Crazy monster attacks!
Dangerous monster attacks!

Crazy monster attacks!
Dangerous monster attacks!

Number of crazy monsters in a team: 7
Crazy monster attacks!
Dangerous monster attacks!

*/