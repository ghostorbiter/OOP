#pragma once
#include <iostream>
#include "monster.hpp"
using namespace std;

class DangerousMonster : virtual public Monster
{
public:
	virtual void attack() const override
	{
		cout << "Dangerous Monster Attacks!" << endl;
	}
};