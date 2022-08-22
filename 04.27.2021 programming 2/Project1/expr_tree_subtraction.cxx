#include "expr_tree_subtraction.hpp"

ExprTreeSubtraction::ExprTreeSubtraction(ExprTree* left, ExprTree* right) : left(left), right(right) {}

ExprTreeSubtraction::~ExprTreeSubtraction()
{
	delete right;
	delete left;
}

void ExprTreeSubtraction::addRight(ExprTree* a_right)
{
	right = a_right;
}

int ExprTreeSubtraction::calculate() const
{
	return left->calculate() - right->calculate();
}