#include <iostream>
#include "song.h"
using namespace std;

const string names[5] = { "Pop", "Rock", "Electronic", "Country", "Blues" };

//**********************STAGE 1**********************

Song::Song(string auth, string _title, Genre _genre, int len) : author(auth), title(_title), genre(_genre), length(len)
{}

bool operator==(const Song& s1, const Song& s2)
{
	return (s1.author == s2.author && s1.title == s2.title);
}

ostream& operator<<(ostream& out, const Song& s1)
{
	int sec = s1.length % 60;
	if (sec > 9) {
		out << s1.author << " - " << s1.title << "(" << s1.length / 60 << ":" << s1.length % 60 << ")" << "[" << names[static_cast<int>(s1.genre)] << "]" << endl;
		return out;
	}
	else {
		out << s1.author << " - " << s1.title << "(" << s1.length / 60 << ":0" << s1.length % 60 << ")" << "[" << names[static_cast<int>(s1.genre)] << "]" << endl;
		return out;
	}
}