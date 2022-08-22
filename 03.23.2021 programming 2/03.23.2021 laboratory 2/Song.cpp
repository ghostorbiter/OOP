#include "Song.h"

const char Genre_name[5][MAX_SONG_NAME_LENGTH]{ "UNDEFINED", "ROCK", "POP", "RAP", "JAZZ" };

Song::Song() : length_in_seconds(0), name("\0") {}

Song::Song(const char song_name[MAX_SONG_NAME_LENGTH], int length_in_seconds)
{
	this->length_in_seconds = length_in_seconds;
	strncpy_s(this->name, song_name, MAX_SONG_NAME_LENGTH);
}

Song::Song(const char song_name[MAX_SONG_NAME_LENGTH], int minutes, int seconds)
{
	this->length_in_seconds = minutes * 60 + seconds;
	strncpy_s(this->name, song_name, MAX_SONG_NAME_LENGTH);
}

Song::Song(const char song_name[MAX_SONG_NAME_LENGTH], int length_in_seconds, Genre gen)
{
	this->length_in_seconds = length_in_seconds;
	strncpy_s(this->name, song_name, MAX_SONG_NAME_LENGTH);
	this->gen = gen;
}

Song::Song(const char song_name[MAX_SONG_NAME_LENGTH], int minutes, int seconds, Genre gen)
{
	this->length_in_seconds = minutes * 60 + seconds;
	strncpy_s(this->name, song_name, MAX_SONG_NAME_LENGTH);
	this->gen = gen;
}

ostream& operator<<(ostream& os, const Song& song) 
{
	int min, sec;
	min = song.length_in_seconds / 60;
	sec = song.length_in_seconds % 60;
	os << song.name << ", length: " << min << "m " << sec << "s, genre: " << Genre_name[song.gen];
	return os;
}

bool operator== (const Song& s1, const Song& s2)
{
	if (!strcmp(s1.name, s2.name) && s1.length_in_seconds == s2.length_in_seconds && s1.gen == s2.gen)
		return 1;
	return 0;
}