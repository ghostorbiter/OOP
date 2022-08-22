#include "expr_tree_number.hpp"
#include <stdexcept>


ExprTreeNumber::ExprTreeNumber(int value) : value(value) {}

int ExprTreeNumber::calculate() const
{
	return value;
}

void ExprTreeNumber::addRight(ExprTree* child)
{
	throw std::logic_error("Adding children to number");
}