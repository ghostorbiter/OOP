#pragma once

#include <iostream>
#include "Song.h"

#define MAX_PLAYLIST_LENGTH 10

using namespace std;

class Playlist {

private:
    Song songs[MAX_PLAYLIST_LENGTH];
    int number_of_songs;

public:
    Playlist();

    friend ostream& operator<<(ostream& os, const Playlist& playlist);

    friend Playlist& operator+=(Playlist& playlist, const Song& song);
    friend Playlist& operator-=(Playlist& playlist, const Song& song);

    friend void exchange_songs(Playlist& p1, Playlist& p2);
};
