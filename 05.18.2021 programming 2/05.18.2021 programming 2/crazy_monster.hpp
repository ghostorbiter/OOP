#pragma once
#include <iostream>
#include "monster.hpp"
using namespace std;

class CrazyMonster : virtual public Monster
{
public:
	virtual void attack() const override
	{
		cout << "Crazy Monster Attacks!" << endl;
	}
};