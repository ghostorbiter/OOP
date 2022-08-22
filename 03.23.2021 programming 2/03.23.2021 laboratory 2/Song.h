#pragma once

#include <iostream>

#define MAX_SONG_NAME_LENGTH 100

using namespace std;

enum Genre {
    UNDEFINED,
    ROCK,
    POP,
    RAP,
    JAZZ
};

class Song {

private:
    Genre gen = UNDEFINED;
    char name[MAX_SONG_NAME_LENGTH];
    int length_in_seconds;

public:
    Song();
    Song(const char song_name[MAX_SONG_NAME_LENGTH], int length_in_seconds);
    Song(const char song_name[MAX_SONG_NAME_LENGTH], int minutes, int seconds);
    Song(const char song_name[MAX_SONG_NAME_LENGTH], int length_in_seconds, Genre gen);
    Song(const char song_name[MAX_SONG_NAME_LENGTH], int minutes, int seconds, Genre gen);

    friend ostream& operator<<(ostream& os, const Song& song);

    friend bool operator== (const Song& s1, const Song& s2);
};