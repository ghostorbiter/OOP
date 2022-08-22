#include <queue>
#include <stdexcept>
#include "cartographer.hpp"
using namespace std;


void Cartographer::clearPath()
{
	auto i = [](TerrainState& a) {
		if (a == TerrainState::Visited)
			a = TerrainState::Accessible;
	};

	for_each(positions.begin(), positions.end(), i);
}

bool Cartographer::findRoute(int x, int y, int finishx, int finishy)
{
	queue<pair<int, int>> candidates;

	if (is_x_inRange(x) && is_y_inRange(y) && is_x_inRange(finishx) && is_y_inRange(finishy)) {
		candidates.push(make_pair(x, y));

		int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

		while (candidates.size() > 0) {
			pair<int, int> p = candidates.front();
			candidates.pop();

			if (is_x_inRange(p.first) && is_y_inRange(p.second))
				setVisited(p.first, p.second);

			if (p == make_pair(finishx, finishy))
				return true;

			for (int i = 0; i < 4; i++) {
				int a = p.first + dir[i][0];
				int b = p.second + dir[i][1];

				if (is_x_inRange(a) && is_y_inRange(b) && !isInaccessible(a, b) && !isVisited(a, b)) {
					setVisited(a, b);
					candidates.push(make_pair(a, b));
				}
			}
		}
	}
	clearPath();
	return false;
}