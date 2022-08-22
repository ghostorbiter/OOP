#include <iostream>
#include <complex>
#include <string>
#include <vector>
#include <algorithm>
#include "linkedStack.h"
#include "expression.h"
using namespace std;

// Stage 3
string rpn(string symbolic_expression);

int main()
{
	std::cout << std::endl << " --------------------- STAGE_0 (0 Pts) --------------------- " << std::endl;
	// Comment STAGE_0 before staring

	//linkedStack stack;
	//linkedStack otherStack;
	//linkedStack newStack;

	//cout << "Stack content, stack: "
	//	<< endl;
	//cout << stack << endl;

	////Add elements into stack
	//stack.push(34);
	//stack.push(43);
	//stack.push(27);

	//cout << "Stack content, stack: "
	//	<< endl;
	//cout << stack << endl;

	////Use the assignment operator to copy the elements
	////of stack into newStack
	//newStack = stack;

	//cout << "After the assignment operator, newStack: "
	//	<< endl;

	////Output the elements of newStack
	//while (!newStack.isEmptyStack())
	//{
	//	cout << newStack.top() << endl;
	//	newStack.pop();
	//}
	//cout << endl;

	////Use the assignment operator to copy the elements
	////of stack into otherStack
	//otherStack = stack;

	//cout << "Testing the copy constructor." << endl;

	//linkedStack testCopy(otherStack);

	//cout << "After the copy constructor, testCopy: " << endl;

	//while (!testCopy.isEmptyStack())
	//{
	//	cout << testCopy.top() << endl;
	//	testCopy.pop();
	//}

	std::cout << std::endl << " --------------------- STAGE_1 (1 Pts) --------------------- " << std::endl;
	
	string to_evaluate("( 3 + 5 ) * 2");
	string element;
	stringstream iss(to_evaluate);
	vector<expression> v;

	while (iss >> element)
		v.push_back(expression(element));

	for (auto& s : v)
		cout << s.get_symbol();
	cout << endl;
	sort(v.begin(), v.end());
	for (auto& s : v)
		cout << s.get_symbol();
	cout << endl;
	
	std::cout << std::endl << " --------------------- STAGE_2 (5 Pts) --------------------- " << std::endl;
	
	linkedStack<int> stack;
	linkedStack<int> otherStack;
	linkedStack<int> newStack;

	cout << "Stack content, stack: "
		<< endl;
	cout << stack << endl;

	//Add elements into stack
	stack.push(34);
	stack.push(43);
	stack.push(27);

	cout << "Stack content, stack: "
		<< endl;
	cout << stack <<endl;

	//Use the assignment operator to copy the elements
	//of stack into newStack
	newStack = stack;

	cout << "After the assignment operator, newStack: "
		<< endl;

	//Output the elements of newStack
	while (!newStack.isEmptyStack())
	{
		cout << newStack.top() << endl;
		newStack.pop();
	}
	cout << endl;

	//Use the assignment operator to copy the elements
	//of stack into otherStack
	otherStack = stack;

	cout << "Testing the copy constructor." << endl;

	linkedStack<int> testCopy(otherStack);

	cout << "After the copy constructor, testCopy: " << endl;

	while (!testCopy.isEmptyStack())
	{
		cout << testCopy.top() << endl;
		testCopy.pop();
	}
	cout << endl;

	linkedStack<string> sstack;
	linkedStack<string> sotherStack;
	linkedStack<string> snewStack;

	cout << "Stack content, stack: "
		<< endl;
	cout << sstack << endl;

	//Add elements into stack
	sstack.push("programming");
	sstack.push("love");
	sstack.push("I");

	cout << "Stack content, stack: "
		<< endl;
	cout << sstack << endl;

	//Use the assignment operator to copy the elements
	//of stack into newStack
	snewStack = sstack;

	cout << "After the assignment operator, newStack: "
		<< endl;

	//Output the elements of newStack
	while (!snewStack.isEmptyStack())
	{
		cout << snewStack.top() << endl;
		snewStack.pop();
	}
	cout << endl;

	//Use the assignment operator to copy the elements
	//of stack into otherStack
	sotherStack = sstack;

	cout << "Testing the copy constructor." << endl;

	linkedStack<string> stestCopy(sotherStack);

	cout << "After the copy constructor, testCopy: " << endl;

	while (!stestCopy.isEmptyStack())
	{
		cout << stestCopy.top() << endl;
		stestCopy.pop();
	}
	
	std::cout << std::endl << " --------------------- STAGE_3 (2 Pts) --------------------- " << std::endl;
	
	cout << "3 + 5 * 2  in RPN is:  ";
	cout << rpn("3 + 5 * 2") << endl;
	cout << "(3 + 5) * 2  in RPN is:  ";
	cout << rpn("( 3 + 5 ) * 2") << endl;
	cout << "6 / 3 * (2 + 5)  in RPN is:  ";
	cout << rpn("6 / 3 * ( 2 + 5 )") << endl;
	cout << "3 / 6 * (0.25 + 0.25)  in RPN is:  ";
	cout << rpn("3 / 6 * ( 0.25 + 0.25 )") << endl;
	cout << endl;
	
	return 0;
}


string rpn(string symbolic_expression)
{
	string element;
	string rpn_expression;
	stringstream iss(symbolic_expression);
	linkedStack<expression> s;

	int i = 0;
	while (iss >> element)
	{
		expression e(element);
		element.clear();

		// TO DO
		if (e.check_priority() == 0)
			cout << e.get_symbol() << " ";

		else if (e.check_priority() == 2 || e.check_priority() == 3) {
			if (s.isEmptyStack() || e.check_priority() > s.top().check_priority())
				s.push(e);
			else {
				while (!s.isEmptyStack()) {
					if (e.check_priority() <= s.top().check_priority()) {
						cout << s.top().get_symbol();
						s.pop();
					}
					else
						break;
				}
				s.push(e);
			}
		}

		else if (e.check_priority() == 1) {
			if (e.get_symbol() == "(")
				s.push(e);
			else {
				while (!s.isEmptyStack()) {
					if (s.top().get_symbol() != "(") {
						cout << s.top().get_symbol();
						s.pop();
					}
					else if (s.top().get_symbol() == "(")
						s.pop();
					else
						break;
				}
			}

		}
	}
		while (!s.isEmptyStack())
		{
			rpn_expression += s.top().get_symbol() + ' ';
			s.pop();
		}
	return rpn_expression;
	
}

