#include "expr_tree_negation.hpp"

void ExprTreeNegation::addRight(ExprTree* right)
{
	child = right;
}

int ExprTreeNegation::calculate() const
{
	return -1 * child->calculate();
}

ExprTreeNegation::ExprTreeNegation(ExprTree* child) : child(child) {}

ExprTreeNegation::~ExprTreeNegation()
{
	delete child;
	child = nullptr;
}
