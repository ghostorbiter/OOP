#include <iostream>
using namespace std;
#include <iomanip>
#include <string.h>
#include "Video.h"

//char* video::getname() const {
//	char names[MAX];
//	strcpy_s(names, name);
//	return names;
//}
int video::getlength() const { return length; }
int video::getcurrent_time() const { return current_time; }

bool& video::set_mute() { return mute; }
bool& video::set_ads() { return ads; }

void video::change_quality(int a_quality) {
	if (strcmp(name, "NONE") && strcmp(author, "NONE"))
		quality = a_quality;
	else
		quality = 0;
}

video::video(const char* a_author, const char* a_name, int a_length, int a_quality) {
	int c = 0;
	int i = (int)strlen(a_author);
	for (c; c < i; c++) {
		author[c] = a_author[c];
	}
	author[c] = '\0';
	c = 0;
	i = (int)strlen(a_name);
	for (c; c < i; c++) {
		name[c] = a_name[c];
	}
	name[c] = '\0';
	length = a_length;
	quality = a_quality;
}

video::video() {
	int c = 0;
	const char* none = "NONE";
	for (c; c < 4; c++) {
		author[c] = none[c];
		name[c] = none[c];
	}
	author[c] = '\0';
	name[c] = '\0';
	length = 0;
	quality = 0;
}

void human_language(int second) {
	if (second < 0) {
		cout << "Video is less than 0 seconds" << endl;
		return;
	}
	else if (second >= 0 && second < 60) {
		if (second < 10)
			cout << "00:00:0" << second;
		else
			cout << "00:00:" << second;
	}
	else if (second >= 60 && second < 3600) {
		int min = second / 60;
		int sec = second % 60;
		if (min < 10) {
			if (sec < 10)
				cout << "00:0" << min << ":0" << sec;
			else
				cout << "00:0" << min << ":" << sec;
		}
		else {
			if (sec < 10)
				cout << "00:" << min << ":0" << sec;
			else
				cout << "00:" << min << ":" << sec;
		}
	}
	else {
		int hours, min, sec;
		min = second / 60;
		sec = second % 60;
		hours = min / 60;
		min = min % 60;
		if (hours < 10) {
			if (min < 10) {
				if (sec < 10)
					cout << "0" << hours << ":0" << min << ":0" << sec;
				else
					cout << "0" << hours << ":0" << min << ":" << sec;
			}
			else {
				if (sec < 10)
					cout << "0" << hours << ":" << min << ":0" << sec;
				else
					cout << "0" << hours << ":" << min << ":" << sec;
			}
		}
		else {
			if (min < 10) {
				if (sec < 10)
					cout << hours << ":0" << min << ":0" << sec;
				else
					cout << hours << ":0" << min << ":" << sec;
			}
			else {
				if (sec < 10)
					cout << hours << ":" << min << ":0" << sec;
				else
					cout << hours << ":" << min << ":" << sec;
			}
		}
	}
}


ostream& operator<<(ostream& out, const video& vid) {
	out << "Author: " << vid.author << endl << "Name: " << vid.name << endl << "Quality: " << vid.quality << endl;
	human_language(vid.current_time);
	cout << " ----- ";
	human_language(vid.length);
	cout << endl;
	return out;
}
istream& operator>>(istream& in, video& vid) {
	cout << "Enter author, video name, length and quality" << endl;
	in >> vid.author >> vid.name >> vid.length >> vid.quality;
	return in;
}


void video::skip()
{
	current_time += 5;
	if (current_time > length)
		current_time = 0;
}

void video::skip(int seconds) {
	current_time += seconds;
	if (current_time > length)
		current_time = 0;
}

void video::skip(int minutes, int seconds) {
	int sec = minutes * 60 + seconds;
	current_time += sec;
	if (current_time > length)
		current_time = 0;
}

void video::skip(int hours, int minutes, int seconds) {
	int sec = hours*3600 + minutes * 60 + seconds;
	current_time += sec;
	if (current_time > length)
		current_time = 0;
}

bool ifSameAuth(video a, video b)
{
	return !strcmp(a.author, b.author);
}

int seconds_left(video a) {
	int time = a.length - a.current_time;
	if (time < 0)
		return 0;
	else
		return time;
}

void video::display_ad() {
	int c = (int)strlen(ad);
	for (int i = 0; i < c; i++) {
		cout << ad[i];
	}
	cout << endl;
}

void video::change_ad(const char* ad1) {
	if (strcmp(name, "NONE") && strcmp(author, "NONE")) {
		int i = (int)strlen(ad1);
		int c = 0;
		for (c; c < i; c++) {
			ad[c] = ad1[c];
		}
		ad[c] = '\0';
	}
}

void video::display_mute() {
	if (mute == false)
		cout << "Video is not muted" << endl;
	else
		cout << "Video is muted" << endl;
}

void video::display_current_time() {
	if (current_time > length)
		current_time = 0;
	human_language(current_time);
}

void video::display_quality() {
	if (quality < 0) {
		cout << "quality is incorrect" << endl;
		quality = 0;
	}
	else
		cout << "Video is " << quality << "p quality" << endl;
}

void VideoLibrary::append(video* a) {
	if (head == NULL && tail == NULL) {
		head = tail = a;
		a->Next = NULL;
		a->Prev = NULL;
	}
	else {
		tail->Next = a;
		a->Prev = tail;
		tail = a;
		a->Next = NULL;
	}
}


void VideoLibrary::prepend(video* a) {
	if (head == NULL && tail == NULL) {
		head = tail = a;
		a->Next = NULL;
		a->Prev = NULL;
	}
	else {
		head->Prev = a;
		a->Next = head;
		head = a;
		a->Prev = NULL;
	}
}

void VideoLibrary::remove_first() {
	if (head == NULL && tail == NULL) {
		return;
		head = tail = NULL;
	}
	if (head == tail) {
		head = tail = NULL;
	}
	else {
		head = head->Next;
		head->Prev->Next = NULL;
		head->Prev = NULL;
	}
}

void VideoLibrary::remove_last() {
	if (head == NULL && tail == NULL)
		return;
	if (head == tail) {
		head = tail = NULL;
	}
	else {
		tail = tail->Prev;
		tail->Next->Prev = NULL;
		tail->Next = NULL;
	}
}

void VideoLibrary::remove(video* c) {
	if (head == NULL && tail == NULL)
		return;
	if (head == tail && head == c) {
		head = tail = NULL;
	}
	if (head == c) {
		remove_first();
	}
	if (tail == c) {
		remove_last();
	}
	else {
		video* a = head;
		while (a != NULL) {
			if (a == c) {
				a->Next->Prev = a->Prev;
				a->Prev->Next = a->Next;
				a->Next = a->Prev = NULL;
				break;
			}
			else
				a = a->Next;
		}
	}
}

void VideoLibrary::clear_library() {
	if (head == NULL && tail == NULL)
		return;
	while (head) {
		remove_first();
	}
	head = tail = NULL;
}

//void VideoLibrary::reverse_list() {
//	if (head == NULL && tail == NULL)
//		return;
//	if (head == tail) {
//		head = tail = NULL;
//		return;
//	}
//	video* temp = head;
//	video* copy = head;
//	video* nextvid = NULL;
//	video* prevvid = NULL;
//	video* revvid = NULL;
//	video* ravvid = NULL;
//	while (&temp->Next != NULL) {
//		head = temp;
//		nextvid = temp->Next;
//		prevvid = temp->Prev;
//		temp->Next = revvid;
//		temp->Prev = ravvid;
//		revvid = temp;
//		ravvid = nextvid->Next;
//		temp = nextvid;
//	}
//	tail = copy;
//}

//VideoLibrary filter(const char* name, VideoLibrary& BS) {
//	VideoLibrary* lib = { NULL };
//	if (BS.head == NULL && BS.tail == NULL)
//		return *lib;
//	video* a = BS.head;
//	char* names;
//	while (&a->Next != NULL) {
//		names = a->getname();
//		if (strcmp(names, name)) {
//			lib->append(a);
//		}
//		a = a->Next;
//	}
//	return *lib;
//}

void VideoLibrary::filter(int time) {
	if (head == NULL && tail == NULL)
		return;
	int c;
	video* a = head;
	video* b = a;
	if (time < 0) {
		while (a != NULL) {
			c = a->getlength();
			if (time <= c) {
				remove(a);
			}
			a = a->Next;
		}
	}
	else{
		while (a != NULL) {
			c = a->getlength();
			if (time >= c) {
				b = a->Next;
				remove(a);
				a = b;
			}
			else
				a = a->Next;
		}
	}
}


void VideoLibrary::print_library() {
	if (head == NULL && tail == NULL) {
		cout << "Empty library" << endl;
	}
	else {
		video* a = head;
		while (a != NULL) {
			cout << *a << endl;
			a = a->Next;
		}
	}
}