#define _CRT_SECURE_NO_WARNINGS
#include "MyText.h" 
#include <string.h>

// _n - number of characters in _arr without trailing '\0'
// _arr - pointer to null terminated array
void MyText::init(int _n, const char* _arr) {

	if (_n < 0) {
		txt = nullptr;
		n = 0;
	}
	else {
		n = _n+1;
		txt = new (nothrow) char[n];
		if (!txt) { n = 0; return; }

		if (_arr == nullptr)
			for (int i = 0; i < n; ++i)
				txt[i] = '\0';
		else {
			for (int i = 0; i < _n; ++i)
				txt[i] = _arr[i];
			txt[n - 1] = '\0';
		}
	}

}

MyText::MyText(const char *p){
	if (p != nullptr) {
		int len = strlen(p);
		this->init(len, p);
	}
	else
		this->init(0, nullptr);
}

MyText::MyText(const MyText &org){
	MyText(org.txt);
}

MyText & MyText::operator=(const MyText &rh){
	if (this == &rh)
		return *this;
	int len = 0;
	if(rh.txt)
		len = strlen(rh.txt);
	this->init(len, rh.txt);
	return *this;
}

MyText::~MyText(){
	n = 0;
	delete[] txt;
}

ostream & operator<<( ostream & os, const MyText & s){
	if(s.txt!=nullptr)
		os<<s.txt;
	else os<<"(empty sentence)";

	return os;
}