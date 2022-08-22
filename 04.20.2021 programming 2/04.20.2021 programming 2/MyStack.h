#pragma once
#include <iostream>
#include "MyText.h" 

using namespace std;

class MyStack
{
	MyText* elements;
	int size;
	int tos; //top of stack
public:
	explicit MyStack(int size=0);
	~MyStack();	
	MyStack(const MyStack &);
	MyStack & operator=(const MyStack &rh);
	MyText pop();
	void push(const MyText	 &);
	bool isEmpty() const;
	int getSize() const { return size; }

	MyStack sort();

};
