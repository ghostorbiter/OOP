#pragma once
#include <iostream>
#include "monster.hpp"
#include "crazy_monster.hpp"
#include "dangerous_monster.hpp"
using namespace std;

class CrazyDangerousMonster : public CrazyMonster, public DangerousMonster
{
public:
	virtual void attack() const override
	{
		CrazyMonster::attack();
		DangerousMonster::attack();
	}
};