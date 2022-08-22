#pragma once
#define MAX 100


class video {
	int length = 0;
	int current_time = 0;
	int quality = 0;
	char name[MAX];
	char author[MAX];
	bool mute = false;
	bool ads = false;
	char ad[MAX] = "There is no ads right now";
public:
	video(const char* a_author, const char* a_name, int a_length, int a_quality);
	video();

	//char* getname() const;
	int getlength() const;
	int getcurrent_time() const;

	bool& set_mute();
	bool& set_ads();

	void change_quality(int a_quality);
	void display_mute();
	void display_quality();
	void display_ad();
	void change_ad(const char* ad1);

	friend istream& operator>> (istream& in, video& vid);
	friend ostream& operator<< (ostream& out, const video& vid);

	friend bool ifSameAuth(video a, video b);
	//friend void human_language(int second);

	void display_current_time();
	void skip();
	void skip(int seconds);
	void skip(int minutes, int seconds);
	void skip(int hours, int minutes, int seconds);
	friend int seconds_left(video a);

	video* Next = NULL;
	video* Prev = NULL;
};

class VideoLibrary {
	video* head = NULL;
	video* tail = NULL;
public:
	void append(video* a);
	void prepend(video* a);
	void remove(video* c);
	void clear_library();
	void remove_first();
	void remove_last();
	//void reverse_list();
	//friend VideoLibrary filter(const char* name, VideoLibrary& BS);
	void filter(int time);

	void print_library();
};


void human_language(int second);