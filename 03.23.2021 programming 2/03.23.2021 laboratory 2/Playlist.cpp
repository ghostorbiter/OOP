#include "Playlist.h"


Playlist::Playlist() : number_of_songs(0), songs() {}

ostream& operator<<(ostream& os, const Playlist& playlist)
{
	if (playlist.number_of_songs == 0) {
		os << "Playlist is empty" << endl;
		return os;
	}
	else {
		for (int i = 0; i < playlist.number_of_songs; i++) {
			os << i+1 << ". " << playlist.songs[i] << endl;
		}
		return os;
	}
}

Playlist& operator+=(Playlist& playlist, const Song& song)
{
	if (playlist.number_of_songs >= MAX_PLAYLIST_LENGTH) { return playlist; }
	else {
		playlist.songs[playlist.number_of_songs] = song;
		playlist.number_of_songs += 1;
		return playlist;
	}
}

Playlist& operator-=(Playlist& playlist, const Song& song)
{
	if (playlist.number_of_songs <= 0) { return playlist; }
	Song copy{};
	int k = playlist.number_of_songs;
	for (int i = 0; i < playlist.number_of_songs; i++) {
		if (playlist.songs[i] == song) {
			for (int q = i; q < playlist.number_of_songs; q++) {
				playlist.songs[q] = playlist.songs[q + 1];
			}
			playlist.songs[k-1] = copy;
			k -= 1;
			break;
		}
	}
	playlist.number_of_songs = k;
	return playlist;
}

void exchange_songs(Playlist& p1, Playlist& p2)
{
	Playlist p3;
	Song copy{};
	if (p1.number_of_songs > p2.number_of_songs) {
		for (int i = 0; i < p2.number_of_songs; i++) {
			p3 += p2.songs[i];
		}
		for (int i = 0; i < p1.number_of_songs; i++) {
			p2.songs[i] = p1.songs[i];
		}
		for (int i = 0; i < p3.number_of_songs; i++) {
			p1.songs[i] = p3.songs[i];
		}
		for (int i = p3.number_of_songs; i < p1.number_of_songs; i++) {
			p1.songs[i] = copy;
		}
	}
	else if (p2.number_of_songs > p1.number_of_songs) {
		for (int i = 0; i < p1.number_of_songs; i++) {
			p3 += p1.songs[i];
		}
		for (int i = 0; i < p2.number_of_songs; i++) {
			p1.songs[i] = p2.songs[i];
		}
		for (int i = 0; i < p3.number_of_songs; i++) {
			p2.songs[i] = p3.songs[i];
		}
		for (int i = p3.number_of_songs; i < p2.number_of_songs; i++) {
			p2.songs[i] = copy;
		}
	}
	else {
		for (int i = 0; i < p1.number_of_songs; i++) {
			p3 += p1.songs[i];
		}
		for (int i = 0; i < p2.number_of_songs; i++) {
			p1.songs[i] = p2.songs[i];
		}
		for (int i = 0; i < p3.number_of_songs; i++) {
			p2.songs[i] = p3.songs[i];
		}
	}
}