#ifndef __CARTOGRAPHER__
#define __CARTOGRAPHER__

#include <vector>
#include <queue>
#include <algorithm>
#include "terrain_map.hpp"
using namespace std;

// Part 4
class Cartographer : public TerrainMap
{
public:
	Cartographer(int x, int y) : TerrainMap(x, y) {}
	void clearPath();
	bool findRoute(int x, int y, int finishx, int finishy);
};

// TO DO



#endif
