#include <iostream>
#include "playlist.h"
using namespace std;

//**********************STAGE 1**********************
Playlist::Playlist(string _name) :name(_name) {}

void Playlist::add_song(Song _song)
{
	for (auto i : songs)
	{
		if (i == _song)
			return;
	}

	songs.push_back(_song);
}

void Playlist::add_songs(list<Song>& list)
{
	songs.splice(songs.end(), list);
}

void Playlist::add_songs(Playlist& playlist)
{
	this->add_songs(playlist.songs);
}

ostream& operator<<(ostream& out, const Playlist& playlist)
{
	out << "Playlist: " << playlist.name << endl;

	if (playlist.songs.empty()) {
		out << "There's no songs in this playlist!" << endl << endl;
		return out;
	}

	for (auto it = playlist.songs.begin(); it != playlist.songs.end(); it++)
		out << (*it);

	out << endl;
	return out;
}

//**********************STAGE 2**********************
void Playlist::insert_song_by_genre(list<Song> list)
{
	auto it = list.begin();
	for (auto it1 = songs.begin(); it1 != songs.end(); it1++)
		if ((*it1) == (*it)) {
			it++;
			it1 = songs.begin();
		}
		/*else if (it == list.end()++)
			return;*/
	
	for (auto it1 = songs.begin(); it1 != songs.end(); it1++) {
		if ((*it).get_genre() == (*it1).get_genre()) {
			songs.insert(it1--, (*it));
			return;
		}
	}

	songs.push_back((*it));
}

//**********************STAGE 3**********************
void Playlist::remove_by_genre(Genre _genre)
{
	for (auto it = songs.begin(); it != songs.end(); ) {
		if ((*it).get_genre() == _genre) {
			auto tmp = it;
			it++;
			songs.erase(tmp);
		}
		else
			it++;
	}
}

void Playlist::remove_by_author(string auth)
{
	auto auth_cmp = [&auth](const Song& s) {
		if (s.get_author() == auth) 
			return true; 
		return false;
	};

	songs.remove_if(auth_cmp);
}

void Playlist::remove_by_length(int len)
{
	LengthCheck lenCheck(len);
	songs.remove_if(lenCheck);
}

//**********************STAGE 4**********************
Playlist merge(string _name, Playlist playlist[], int n)
{
	Playlist np(_name);

	for (int i = 0; i < n; i++) {
		for (auto it = playlist[i].songs.begin(); it != playlist[i].songs.end(); it++)
			np.add_song((*it));
	}

	return np;
}