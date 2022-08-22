#ifndef __TERRAIN_MAP__
#define __TERRAIN_MAP__

#include <vector>
#include <iostream>

#include "map_interface.hpp"
using namespace std;

class TerrainMap : public MapInterface {
protected:
    // Part 1
    enum class TerrainState { Inaccessible, Accessible, Visited };
    int cols;
    int rows;
    vector<TerrainState> positions;

public:
    // Part 1

    // TO DO
    TerrainMap(int, int);

    bool isAccessible(int x, int y) const override;
    bool isInaccessible(int x, int y) const override;
    bool isVisited(int x, int y) const override;
    bool is_x_inRange(int x) const override;
    bool is_y_inRange(int x) const override;
    void setAccessible(int x, int y) override;
    void setInaccessible(int x, int y) override;
    int getCols() const override { return cols; }
    int getRows() const override { return rows; }

    // Part 2
    void setVisited(int x, int y);
    int visitedCount() const;


    // Part 3
    TerrainMap& operator!();

};


#endif
