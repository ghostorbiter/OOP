#pragma once
#include <iostream>
#include <string>
using namespace std;

class expression
{
public:
	enum class expression_type { constant, math_operator, bracket };
private:
	string symbol;
	int priority;
	expression_type type;
public:
	expression();
	expression(string element);
	int check_priority() const { return priority; }
	expression_type check_type() const { return type; }
	string get_symbol() const { return symbol; }
	// Stage 1
	friend bool operator>(const expression& e1, const expression& e2);
	friend bool operator<(const expression& e1, const expression& e2);
};

//Implementation

expression::expression() : symbol(""), priority(0)
{
	type = expression_type::constant;
}

expression::expression(string element) : symbol(element), priority(0)
{
	if (element == "(" || element == ")")
	{
		priority = 1; type = expression_type::bracket;
	}
	else if (element == "+" || element == "-")
	{
		priority = 2;  type = expression_type::math_operator;
	}
	else if (element == "*" || element == "/")
	{
		priority = 3; type = expression_type::math_operator;
	}
	else
	{
		type = expression_type::constant;
	}
}

// Stage 1 
//TO DO

bool operator>(const expression& e1, const expression& e2)
{
	if (e1.check_priority() > e2.check_priority())return true;
	return false;
}

bool operator<(const expression& e1, const expression& e2)
{
	if (e1.check_priority() < e2.check_priority())return true;
	return false;
}