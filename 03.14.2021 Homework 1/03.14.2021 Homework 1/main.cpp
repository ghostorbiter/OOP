#include <iostream>
using namespace std;
#include "Video.h"
//#include "Video.cpp"

const char* authors[10] = { "James", "Michael", "PewDiePie", "Polina Here", "Janny", "Bill", "VannosGaming", "EeOneGuy", "Artur Sharifov", "Games Portal" };
const char* namesforvids[10] = { "News", "Sports Today", "Playing Among Us", "CS GO unboxing", "Pumel Party", "Minecraft Survival", "Apex Legends vs CS GO", "Portal 2", "DOOM", "Genshin Impact" };

int main() {
	//Task 1 
	cout << "----------TASK 1----------" << endl;
	video a;
	video b;
	video c(authors[0], namesforvids[0], 800, 720);
	video d(authors[4], namesforvids[3], 1500, 2080);
	cin >> a;
	cout << a << b << c << d;

	//Task 2
	cout << endl << endl << "----------TASK 2----------" << endl;
	a.set_mute() = true;
	b.set_ads() = true;
	c.set_ads() = true;

	a.display_mute();
	b.display_mute();
	c.display_mute();
	d.display_mute();

	a.change_quality(144);
	b.change_quality(2098);
	c.change_quality(280);

	a.display_quality();
	b.display_quality();
	c.display_quality();
	d.display_quality();

	c.change_ad("Samsung Galaxy S21");
	
	a.display_ad();
	b.display_ad();
	c.display_ad();
	d.display_ad();

	//Task 3
	cout << endl << endl << "----------TASK 3----------" << endl;
	if (ifSameAuth(a, c)) {
		cout << "Video a and Video c are made by same author" << endl;
	}
	else {
		cout << "Video a and Video c are not made by same author" << endl;
	}

	int g = a.getlength();
	int t = a.getcurrent_time();
	cout << "Video a" << endl;
	human_language(t);
	cout << " --- ";
	human_language(g);
	cout << endl;

	g = b.getlength();
	t = b.getcurrent_time();
	cout << "Video b" << endl;
	human_language(t);
	cout << " --- ";
	human_language(g);
	cout << endl;

	g = c.getlength();
	t = c.getcurrent_time();
	cout << "Video c" << endl;
	human_language(t);
	cout << " --- ";
	human_language(g);
	cout << endl;

	g = d.getlength();
	t = d.getcurrent_time();
	cout << "Video d" << endl;
	human_language(t);
	cout << "---";
	human_language(g);
	cout << endl;

	//Task 4
	cout << endl << endl << "----------TASK 4----------" << endl;
	int k;
	for (int i = 0; i < 5; i++) {
		d.skip();
		d.display_current_time();
		cout << "->";
		k = seconds_left(d);
		human_language(k);
		cout << endl;
	}
	cout << endl;

	a.skip(20);
	a.display_current_time();
	cout << "->";
	k = seconds_left(a);
	human_language(k);
	cout << endl;

	b.skip(1, 5);
	b.display_current_time();
	cout << "->";
	k = seconds_left(b);
	human_language(k);
	cout << endl;

	a.skip(1, 15);
	a.display_current_time();
	cout << "->";
	k = seconds_left(a);
	human_language(k);
	cout << endl;

	d.skip(0, 1, 5);
	d.display_current_time();
	cout << "->";
	k = seconds_left(d);
	human_language(k);
	cout << endl;

	//Task 5
	cout << endl << endl << "----------TASK 5----------" << endl;
	VideoLibrary VID_LIB;
	VID_LIB.print_library();
	cout << endl;

	VID_LIB.append(&a);
	VID_LIB.prepend(&b);
	VID_LIB.append(&c);
	VID_LIB.prepend(&d);
	VID_LIB.print_library();
	cout << endl;

	//Task 6
	cout << endl << endl << "----------TASK 6----------" << endl;
	VID_LIB.remove(&a);
	VID_LIB.print_library();
	cout<< endl << endl << endl;
	VID_LIB.prepend(&a);
	VID_LIB.print_library();
	cout<< endl;

	//Task 7
	cout << endl << endl << "----------TASK 7----------" << endl;
	VID_LIB.remove_first();
	VID_LIB.print_library();
	cout<< endl;
	VID_LIB.remove_last();
	VID_LIB.print_library();
	cout << endl;

	VID_LIB.clear_library();
	VID_LIB.print_library();
	cout << endl;

	VID_LIB.append(&c);
	VID_LIB.prepend(&b);
	VID_LIB.append(&a);
	VID_LIB.prepend(&d);
	VID_LIB.print_library();
	cout << endl;

	//Task 8
	cout << endl << endl << "----------TASK 8----------" << endl;

	VID_LIB.filter(600);
	VID_LIB.print_library();
	cout << endl << endl << endl;
}