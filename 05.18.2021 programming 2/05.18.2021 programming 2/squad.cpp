#include <iostream>
#include "monster.hpp"
#include "crazy_monster.hpp"
#include "dangerous_monster.hpp"
#include "crazy_dangerous_monster.hpp"
#include "squad.hpp"

using namespace std;

Squad::Squad(const std::string& input) : monsters(nullptr), monster_count(0), squads(nullptr), squad_count(0), total_monster_count(0)
{
	int len = input.length();
	int commas = 0;
	for (int i = 0; i < len; i++) {
		if (input[i] == ',')
			commas++;
	}

	if (len != 0 && commas != 0) {
		int counter = 0;
		monster_count = commas + 1;
		monsters = new Monster * [monster_count];
		for (int i = 0; i < monster_count; i++)
			monsters[i] = nullptr;

		int c = 0;
		for (int q = 0; q < len;  q++) {
			if (input[q] != ',') {
				c++;
			}
			else {

				if (c == 5) {
					monsters[counter] = new CrazyMonster();
					counter++;
				}
				else if (c == 9) {
					monsters[counter] = new DangerousMonster();
					counter++;
				}
				else if (c == 14) {
					monsters[counter] = new CrazyDangerousMonster();
					counter++;
				}

				c = 0;
			}
		}
	}
	else if (len != 0 && commas == 0) {
		monster_count = commas + 1;
		monsters = new Monster * [monster_count];

		if (input == "crazy") {
			monsters[0] = new CrazyMonster();
		}
		else if (input == "dangerous") {
			monsters[0] = new DangerousMonster();
		}
		else if (input == "crazydangerous") {
			monsters[0] = new CrazyDangerousMonster();
		}
	}

	total_monster_count += monster_count;
}

Squad::~Squad()
{
	for (int i = 0; i < squad_count; i++)
		delete squads[i];
	delete[] squads;

	for (int i = 0; i < monster_count; i++)
		delete monsters[i];
	delete[] monsters;

	monster_count = squad_count = 0;
}

int Squad::crazyCount() const
{
	int counter = 0;
	for (int i = 0; i < monster_count; i++)
	{
		if (typeid(CrazyMonster) == typeid(*monsters[i]))
			counter++;
		else if (typeid(CrazyDangerousMonster) == typeid(*monsters[i]))
			counter++;
	}
	
	for (int i = 0; i < squad_count; i++) {
		counter += squads[i]->crazyCount();
	}

	return counter;
}

//Part 2
//void Squad::attack(int index) const
//{
//	if (index > monster_count)
//		return;
//
//	monsters[index]->attack();
//}

//Part 3
//void Squad::attack(int index) const
//{
//	try {
//		if (index > monster_count)
//		{
//			throw "Out of range";
//		}
//	}
//	catch (const char* e)
//	{
//		throw;
//	}
//
//	monsters[index]->attack();
//}

//Part 2B
void Squad::attack(int index) const
{
	try {
		if (index > total_monster_count)
		{
			throw "Out of range";
		}
	}
	catch (const char* e)
	{
		throw;
	}

	if (index > monster_count)
	{
		index -= monster_count;
		for (int i = 0; i < squad_count; i++) {
			if (index > squads[i]->total_monster_count)
				index -= squads[i]->total_monster_count;
			else {
				squads[i]->monsters[index]->attack();
				break;
			}
		}
	}
	else
		monsters[index]->attack();
}

void Squad::recruit(Squad* other_squad)
{
	/*if (other_squad == nullptr)
		return;

	if (squad_count == 0) {
		squads = new Squad * [1];
		squad_count++;
		squads[0]->monster_count = other_squad->monster_count;
		squads[0]->total_monster_count = other_squad->total_monster_count;
		squads[0]->monsters = new Monster * [squads[squad_count - 1]->monster_count];

		for (int i = 0; i < squads[squad_count - 1]->monster_count; i++) {
			squads[squad_count - 1]->monsters[i] = other_squad->monsters[i];
		}
		return;
	}

	auto tmp = new Squad * [squad_count];
	for (int i = 0; i < squad_count; i++)
		tmp[i] = squads[i];

	for (int i = 0; i < squad_count; i++)
		delete squads[i];

	squad_count++;
	squads = new Squad * [squad_count];
	for (int i = 0; i < squad_count; i++)
		squads[i] = tmp[i];

	squads[squad_count - 1]->monster_count = other_squad->monster_count;
	squads[squad_count - 1]->total_monster_count = other_squad->total_monster_count;
	squads[squad_count - 1]->monsters = new Monster * [squads[squad_count - 1]->monster_count];

	for (int i = 0; i < squads[squad_count - 1]->monster_count; i++) {
		squads[squad_count - 1]->monsters[i] = other_squad->monsters[i];
	}*/

	//auto tmp = new Squad * [squad_count];
	//for (int i = 0; i < squad_count; i++)
	//	tmp[i] = squads[i];
	//for (int i = 0; i < squad_count; i++)
	//	delete squads[i];

	//squads = new Squad * [squad_count + 1];
	//for (int i = 0; i < squad_count + 1; i++)
	//	squads[i] = tmp[i];
	//squads[squad_count] = other_squad;
	//squad_count++;
}

//void Squad::recruit(Squad* other_squad)
//{
//	if (other_squad == nullptr)
//		return;
//
//	/*auto tmp = new Squad * [squad_count];
//	for (int i = 0; i < squad_count; i++)
//		tmp[i] = squads[i];
//
//	for (int i = 0; i < squad_count; i++)
//		delete squads[i];
//
//	squad_count++;
//	squads = new Squad * [squad_count];
//	for (int i = 0; i < squad_count; i++)
//		squads[i] = tmp[i];*/
//
//	squad_count++;
//	squads[squad_count - 1]->monsters = new Monster * [other_squad->monster_count];
//	for (int i = 0; i < other_squad->monster_count; i++) {
//		squads[squad_count - 1]->monsters[i] = other_squad->monsters[i];
//	}
//	squads[squad_count - 1]->monster_count = other_squad->monster_count;
//	total_monster_count += other_squad->total_monster_count;
//}