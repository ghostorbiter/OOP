#include <stdexcept>
#include <algorithm>
#include "terrain_map.hpp"
using namespace std;


TerrainMap::TerrainMap(int _col, int _row) : cols(_col), rows(_row), positions(_col*_row, TerrainState::Accessible)
{
	/*for (int i = 0; i < _col * _row; i++) {
		positions.push_back(TerrainState::Accessible);
	}*/
	//positions.resize(_col * _row);
	//for (int i = 0; i < _col * _row; i++)
	//	positions[i] = TerrainState::Accessible;
}

bool TerrainMap::isAccessible(int x, int y) const
{
	if (is_x_inRange(x) && is_y_inRange(y)) {
		if (positions[y * cols + x] == TerrainState::Accessible)
			return true;
		else
			return false;
	}
	else
		throw out_of_range("Out of range");
	
}

bool TerrainMap::isInaccessible(int x, int y) const
{
	if (is_x_inRange(x) && is_y_inRange(y)) {
		if (positions[y * cols + x] == TerrainState::Inaccessible)
			return true;
		else
			return false;
	}
	else
		throw out_of_range("Out of range");
}

bool TerrainMap::isVisited(int x, int y) const
{
	if (is_x_inRange(x) && is_y_inRange(y)) {
		if (positions[y * cols + x] == TerrainState::Visited)
			return true;
		else
			return false;
	}
	else
		throw out_of_range("Out of range");
}

bool TerrainMap::is_x_inRange(int x) const
{
	if (x >= 0 && x < cols)
		return true;
	return false;
}

bool TerrainMap::is_y_inRange(int y) const
{
	if (y >= 0 && y < rows)
		return true;
	return false;
}

void TerrainMap::setAccessible(int x, int y)
{
	if (is_x_inRange(x) && is_y_inRange(y)) {
		positions[y * cols + x] = TerrainState::Accessible;
		return;
	}
	else
		throw out_of_range("Out of range");
	
}

void TerrainMap::setInaccessible(int x, int y)
{
	if (is_x_inRange(x) && is_y_inRange(y)) {
		positions[y * cols + x] = TerrainState::Inaccessible;
		return;
	}
	else
		throw out_of_range("Out of range");
}



ostream& operator<<(ostream& out, const MapInterface& map)
{
	for (int y = 0; y < map.getRows(); y++) {
		for (int x = 0; x < map.getCols(); x++) {
			if (map.isAccessible(x, y))
				out << "0";
			else if (map.isInaccessible(x, y))
				out << "X";
			else
				out << "#";
		}
		out << endl;
	}
	return out;
}



void TerrainMap::setVisited(int x, int y)
{
	if (is_x_inRange(x) && is_y_inRange(y)) {
		positions[y * cols + x] = TerrainState::Visited;
		return;
	}
	else
		throw out_of_range("Out of range");
}

int TerrainMap::visitedCount() const
{
	auto i = [](const TerrainState a) {
		if (a == TerrainState::Visited)
			return true;
		return false;
	};

	return count_if(positions.begin(), positions.end(), i);
}


TerrainMap& TerrainMap::operator!()
{
	auto i = [](TerrainState& a) {
		if (a == TerrainState::Inaccessible)
			a = TerrainState::Accessible;
		else if (a == TerrainState::Accessible)
		a = TerrainState::Inaccessible;
		return a;
	};

	transform(positions.begin(), positions.end(), positions.begin(), i);
	return *this;
}