#define _CRT_SECURE_NO_WARNINGS

#include "MyStack.h"

bool MyStack::isEmpty() const
{
	if (0 == tos)
	{
		//cout << "Stack is empty" << endl;
		return true;
	}
	return false;
}

MyStack::MyStack(int size)
{
	this->size = size;
	this->tos = 0;
	this->elements = new (nothrow) MyText[size];
}

MyStack::~MyStack()
{
	size = tos = 0;
	delete[] elements;
}

MyStack::MyStack(const MyStack& other)
{
	if (this != &other) {

		this->size = other.size;
		this->tos = other.tos;

		delete[] this->elements;
		this->elements = new (nothrow) MyText[size];

		for (int i = 0; i < other.tos; i++) {
			this->elements[i] = other.elements[i];
		}
	}
}

MyStack& MyStack:: operator=(const MyStack& rh)
{
	if (this == &rh)
		return *this;

	this->size = rh.size;
	this->tos = rh.tos;

	delete[] this->elements;
	this->elements = new (nothrow) MyText[size];

	for (int i = 0; i < rh.tos; i++) {
		this->elements[i] = rh.elements[i];
	}

	return *this;
}

MyText MyStack::pop()
{
	MyText tmp = this->elements[0];
	if (tos > 0 && size != 0 && elements != nullptr) {
		int i = 0;
		for (; i < tos-1; i++)
		{
			this->elements[i] = this->elements[i + 1];
		}
		elements[i] = nullptr;
		tos = tos - 1;
		return tmp;
	}
}

void MyStack::push(const MyText& rh)
{
	if (tos == size) {
		size *= 2;
		this->elements = new (nothrow) MyText[size];
	}
	int i = tos;
	for (; i > 0; i--) {
		this->elements[i] = this->elements[i - 1];
	}
	tos++;
	this->elements[0] = rh;
}


//MyStack MyStack::sort()
//{
//	for (int i = 0; i < this->tos;i++)
//	{
//		for (int q = i; q < this->tos;q++)
//		{
//			if (elements[q].getLength > elements[q + 1].getLength)
//			{
//				MyText tmp = elements[q+1];
//				elements[q + 1] = elements[q];
//				elements[q] = tmp;
//			}
//		}
//	}
//}