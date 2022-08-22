#include <iostream>
#include "terrain_map.hpp"
#include "cartographer.hpp"

int main()
{
    cout << "******************************** Part 1 (2,5 pts) ********************************" << endl;
    
    // Creating terrain map
    TerrainMap map(5, 3);

    // Setting elements on map
    map.setInaccessible(2, 0);
    map.setInaccessible(2, 1);
    map.setInaccessible(3, 1);
    map.setInaccessible(4, 1);

    // Checking range of coordinates
    if (!map.is_x_inRange(5) && !map.is_y_inRange(3))
        cout << "Position (5,3) is not in the range of map of " << map.getCols() << " columns and " << map.getRows() << " rows" << endl;
    else
        cout << "Problem with position (5,3)" << endl;
    if (!map.is_x_inRange(-1) && !map.is_y_inRange(-1))
        cout << "Position (-1,-1) is not in the range of map of " << map.getCols() << " columns and " << map.getRows() << " rows" << endl;
    else
        cout << "Problem with position (-1,-1)" << endl;
    if (map.is_x_inRange(1) && map.is_y_inRange(1))
        cout << "Position (1,1) is in the range of map of " << map.getCols() << " columns and " << map.getRows() << " rows" << endl;
    else
        cout << "Problem with position (1,1)" << endl;
    cout << endl;

    // Checking accessibility/inaccessibility
    if (map.isAccessible(2, 0))
        cout << "Position (2,0) is accessible" << endl;
    else
        cout << "Position (2,0) is inaccessible" << endl;

    if (map.isInaccessible(2, 1))
        cout << "Position (2,1) is inaccessible" << endl;
    else
        cout << "Position (2,1) is accessible" << endl;

    if (map.isAccessible(0, 0))
        cout << "Position (0,0) is accessible" << endl;
    else
        cout << "Position (0,0) is inaccessible" << endl;

    if (map.isInaccessible(2, 2))
        cout << "Position (2,2) is inaccessible" << endl;
    else
        cout << "Position (2,2) is accessible" << endl;
    cout << endl;

    // Checking accessible/inaccessible exceptions
    try {
        map.isAccessible(-1, 0);
    }
    catch (out_of_range& ex)
    {
        cout << ex.what() << endl;
    }

    try {
        map.isInaccessible(6, 0);
    }
    catch (out_of_range& ex)
    {
        cout << ex.what() << endl;
    }

    try {
        map.isAccessible(0, -1);
    }
    catch (out_of_range& ex)
    {
        cout << ex.what() << endl;
    }

    try {
        map.isInaccessible(0, 6);
    }
    catch (out_of_range& ex)
    {
        cout << ex.what() << endl;
    }
    cout << endl;

    // Printing terrain map to the screen
    cout << map << endl;
    
    cout << "******************************** Part 2 (1,5 pt) ********************************" << endl;
    
    // Setting visited
    map.setVisited(0, 0);
    map.setVisited(0, 1);
    map.setVisited(0, 2);
    map.setVisited(1, 2);

    // Printing terrain map to the screen
    cout << map;
    cout << "Number of visited elements: " << map.visitedCount() << endl;
    cout << endl;
    
    cout << "******************************** Part 3 (1 pt) ********************************" << endl;
    
    // Printing inverted terrain map to the screen
    cout << !map;
    cout << "Number of visited elements: " << map.visitedCount() << endl;
    cout << endl;
    
    cout << "******************************** Part 4 (1 pts) ********************************" << endl;
    
    // Creating cartographer map
    Cartographer cartographer(5,3);
    cartographer.setInaccessible(2, 0);
    cartographer.setInaccessible(2, 1);
    cartographer.setInaccessible(3, 1);
    cartographer.setInaccessible(4, 1);

    // Setting visited
    cartographer.setVisited(0, 0);
    cartographer.setVisited(0, 1);
    cartographer.setVisited(0, 2);
    cartographer.setVisited(1, 2);

    // Printing cartographer map to the screen
    cout << cartographer << endl;
    cout << endl;
    
    cout << "******************************** Part 5 (0,5 pts) ********************************" << endl;
    
    cartographer.clearPath();
    // Printing cartographer map to the screen
    cout << cartographer << endl;
    cout << endl;
    
    cout << "******************************** Part 6 (1,5 pt) ********************************" << endl;
    
    // finding path
    cartographer.setInaccessible(2, 0);
    cartographer.setInaccessible(2, 1);
    cartographer.setInaccessible(3, 1);
    cartographer.setInaccessible(4, 1);

    if(!cartographer.findRoute(0, 0, 4, 0)) {
        cout << "Route not found!" << endl;
        cout << cartographer << endl;
    }

    if(cartographer.findRoute(0, 0, 4, 2)) {
        cout << "Route found!" << endl;
        cout << cartographer << endl;
    }
    
    return 0;
}
