#ifndef __MAP_INTERFACE__
#define __MAP_INTERFACE__

#include <iostream>
using namespace std;

class MapInterface {
public:
    virtual ~MapInterface() = default;
    virtual bool isAccessible(int x, int y) const = 0;
    virtual bool isInaccessible(int x, int y) const = 0;
    virtual bool isVisited(int x, int y) const = 0;
    virtual bool is_x_inRange(int x) const = 0;
    virtual bool is_y_inRange(int x) const = 0;
    virtual void setAccessible(int x, int y) = 0;
    virtual void setInaccessible(int x, int y) = 0;
    virtual int getCols() const = 0;
    virtual int getRows() const = 0;
    friend ostream& operator<<(ostream& out, const MapInterface& map);
};

#endif
