#include <iostream>
#include "sortedPlaylist.h"
using namespace std;

//**********************STAGE 5**********************
SortedPlaylist::SortedPlaylist(string _name, SortOrder so, SortLabel sl) : Playlist(_name), sortOrder(so), sortLabel(sl) {}

void SortedPlaylist::add_song(Song _song)
{
	Playlist::add_song(_song);
	this->sortPlaylist();
}

void SortedPlaylist::add_songs(list<Song>& list)
{
	Playlist::add_songs(list);
	this->sortPlaylist();
}

void SortedPlaylist::add_songs(Playlist& playlist)
{
	Playlist::add_songs(playlist);
	this->sortPlaylist();
}

void SortedPlaylist::insert_song_by_genre(list<Song> list)
{
	Playlist::insert_song_by_genre(list);
	this->sortPlaylist();
}

void SortedPlaylist::set_sort_settings(SortOrder so, SortLabel sl)
{
	sortOrder = so;
	sortLabel = sl;

	this->sortPlaylist();
}

void SortedPlaylist::sortPlaylist()
{
	/*auto cmp = [&](Song& s1, Song& s2) {
		if (sortLabel == SortLabel::AUTHOR) {
			if (sortOrder == SortOrder::ASCENDING) {
				int i = 0;
				while ((i < s1.get_author().length()) && (i < s2.get_author().length())) {
					if (tolower(s1.get_author()[i]) < tolower(s2.get_author()[i])) return true;
					else if (tolower(s1.get_author()[i]) > tolower(s2.get_author()[i])) return false;
					i++;
				}
				return false;
			}
			else if (sortOrder == SortOrder::DESCENDING) {
				int i = 0;
				while ((i < s1.get_author().length()) && (i < s2.get_author().length())) {
					if (tolower(s1.get_author()[i]) > tolower(s2.get_author()[i])) return true;
					else if (tolower(s1.get_author()[i]) < tolower(s2.get_author()[i])) return false;
					i++;
				}
				return false;
			}
		}
		else if (sortLabel == SortLabel::TITLE) {
			if (sortOrder == SortOrder::ASCENDING) {
				int i = 0;
				while ((i < s1.get_title().length()) && (i < s2.get_title().length())) {
					if (tolower(s1.get_title()[i]) < tolower(s2.get_title()[i])) return true;
					else if (tolower(s1.get_title()[i]) > tolower(s2.get_title()[i])) return false;
					i++;
				}
				return false;
			}
			else if (sortOrder == SortOrder::DESCENDING) {
				int i = 0;
				while ((i < s1.get_title().length()) && (i < s2.get_title().length())) {
					if (tolower(s1.get_title()[i]) > tolower(s2.get_title()[i])) return true;
					else if (tolower(s1.get_title()[i]) < tolower(s2.get_title()[i])) return false;
					i++;
				}
				return false;
			}
		}
	};*/

	auto cmp = [&](Song& s1, Song& s2) {
		if (sortLabel == SortLabel::AUTHOR) {
			if (sortOrder == SortOrder::ASCENDING) {
				int i = 0;
				if (s1.get_author() == s2.get_author()) {
					while ((i < s1.get_title().length()) && (i < s2.get_title().length())) {
						if (tolower(s1.get_title()[i]) < tolower(s2.get_title()[i])) return true;
						else if (tolower(s1.get_title()[i]) > tolower(s2.get_title()[i])) return false;
						i++;
					}
				}
				else {
					while ((i < s1.get_author().length()) && (i < s2.get_author().length())) {
						if (tolower(s1.get_author()[i]) < tolower(s2.get_author()[i])) return true;
						else if (tolower(s1.get_author()[i]) > tolower(s2.get_author()[i])) return false;
						i++;
					}
				}
			}
			else if (sortOrder == SortOrder::DESCENDING) {
				int i = 0;
				if (s1.get_author() == s2.get_author()) {
					while ((i < s1.get_title().length()) && (i < s2.get_title().length())) {
						if (tolower(s1.get_title()[i]) < tolower(s2.get_title()[i])) return true;
						else if (tolower(s1.get_title()[i]) > tolower(s2.get_title()[i])) return false;
						i++;
					}
				}
				else {
					while ((i < s1.get_author().length()) && (i < s2.get_author().length())) {
						if (tolower(s1.get_author()[i]) > tolower(s2.get_author()[i])) return true;
						else if (tolower(s1.get_author()[i]) < tolower(s2.get_author()[i])) return false;
						i++;
					}
				}
			}
		}
		else if (sortLabel == SortLabel::TITLE) {
			if (sortOrder == SortOrder::ASCENDING) {
				int i = 0;
				if (s1.get_title() == s2.get_title()) {
					while ((i < s1.get_author().length()) && (i < s2.get_author().length())) {
						if (tolower(s1.get_author()[i]) < tolower(s2.get_author()[i])) return true;
						else if (tolower(s1.get_author()[i]) > tolower(s2.get_author()[i])) return false;
						i++;
					}
				}
				else {
					while ((i < s1.get_title().length()) && (i < s2.get_title().length())) {
						if (tolower(s1.get_title()[i]) < tolower(s2.get_title()[i])) return true;
						else if (tolower(s1.get_title()[i]) > tolower(s2.get_title()[i])) return false;
						i++;
					}
				}
			}
			else if (sortOrder == SortOrder::DESCENDING) {
				int i = 0;
				if (s1.get_title() == s2.get_title()) {
					while ((i < s1.get_author().length()) && (i < s2.get_author().length())) {
						if (tolower(s1.get_author()[i]) < tolower(s2.get_author()[i])) return true;
						else if (tolower(s1.get_author()[i]) > tolower(s2.get_author()[i])) return false;
						i++;
					}
				}
				else {
					while ((i < s1.get_title().length()) && (i < s2.get_title().length())) {
						if (tolower(s1.get_title()[i]) > tolower(s2.get_title()[i])) return true;
						else if (tolower(s1.get_title()[i]) < tolower(s2.get_title()[i])) return false;
						i++;
					}
				}
			}
		}
	};

	songs.sort(cmp);
}