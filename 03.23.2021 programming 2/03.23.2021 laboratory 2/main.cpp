#include <iostream>

#include "Song.h"
#include "Playlist.h"

using namespace std;

int main() {


    cout << "\n***** Part1 *****\n\n";
    
        Song s00{};
        Song s01{"All Star", 200};
        Song s02{"Take On Me", 3, 45};

        cout << s00 << endl;
        cout << s01 << endl;
        cout << s02 << endl;
    

    cout << "\n***** Part2 *****\n\n";
    
        Song s1{"Gimme Shelter", 4, 30, Genre::ROCK};
        Song s2{"Miss You", 4, 48, Genre::ROCK};
        Song s3{"Billie Jean", 4, 53, Genre::POP};
        Song s4{"Black or White", 4, 14, Genre::POP};
        Song s5{"Without Me", 4, 50, Genre::RAP};
        Song s6{"Lose Yourself", 5, 22, Genre::RAP};
        Song s7{"Blue in Green", 5, 37, Genre::JAZZ};
        Song s8{"On Green Dolphin Street", 9, 49, Genre::JAZZ};
        Song s9{"Roundabout", 9, 49, Genre::ROCK};
        Song s10{"Never Gonna Give You Up", 3, 34};

        cout << s1 << endl;
        cout << s2 << endl;
        cout << s3 << endl;
        cout << s4 << endl;
        cout << s5 << endl;
        cout << s6 << endl;
        cout << s7 << endl;
        cout << s8 << endl;
        cout << s9 << endl;
        cout << s10 << endl;
    

    cout << "\n***** Part3 *****\n\n";
    
        Playlist p1{};
        Playlist p2{};

        cout << p1 << endl;
        cout << p2 << endl;
    

    cout << "\n***** Part4 *****\n\n";
    
        p1 += s1;
        p1 += s2;
        p1 += s3;
        p1 += s4;
        p1 += s5;
        p1 += s6;
        p1 += s7;
        p1 += s8;
        p1 += s9;
        p1 += s10;

        for (int i = 0; i < 20; i++) { //not all of the songs can fit so they won't be added
            p2 += s9;
        }

        p1 -= s5;
        p1 -= s2;
        p1 -= s2; //s2 was already deleted so nothing will happen
        p1 -= s10;

        p2 -= s9;
        p2 -= s9;
        p2 -= s10;

        cout << p1 << endl;
        cout << p2 << endl;
    

    cout << "\n***** Part5 *****\n\n";
    
        cout << p1 << endl;
        cout << p2 << endl;

        exchange_songs(p1, p2);

        cout << p1 << endl;
        cout << p2 << endl;
    

    return 0;
}
