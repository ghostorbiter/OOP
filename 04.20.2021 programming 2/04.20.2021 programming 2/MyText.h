#pragma once

#include <cstring>
#include <iostream>
using std::ostream;
using std::nothrow;

class MyText{
	
	int n;		//size of array i.e. number of characters including '\0'
	char* txt;  //pointer to array
	void init(int _n, const char* _arr);

public:
	MyText(const char* p = nullptr);
	MyText(const MyText&);
	MyText & operator=(const MyText&);
	~MyText();

	int getLength(){ if(txt!= nullptr) return n-1; else return 0; }

	friend ostream & operator<<( ostream & , const MyText &);
};