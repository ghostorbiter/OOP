#include "parser.hpp"
#include "expr_tree.hpp"
#include "expr_tree_number.hpp"
#include "expr_tree_negation.hpp"
#include "expr_tree_subtraction.hpp"

Parser::Parser()
    : top(nullptr), bottom(nullptr)
{
}

bool Parser::parse(const std::string& input)
{
    //TODO: implement using addNumberToTree() and addMinusToTree()
    int pos = 0;
    bool was_number = false;
    bool parsing_number = false;
    std::string number;
    while (pos < input.length()) {
        if (std::isdigit(input[pos])) {
            parsing_number = true;
            number += input[pos];
        }
        else {
            if (parsing_number) {
                int num = std::stoi(number);
                number = "";
                parsing_number = false;
                was_number = true;
                if (!addNumberToTree(num)) {
                    resetTree();
                    return false;
                }
            }
        }
        pos++;
    }
    if (parsing_number) {
        int num = std::stoi(number);
        was_number = true;
        if (!addNumberToTree(num)) {
            resetTree();
            return false;
        }
    }
    if (!was_number || bottom != nullptr) {
        resetTree();
        return false;
    }

    return true;
}

ExprTree* Parser::getExpression() const
{
    return top;
}

/*
TODO: uncomment below 2 methods and call them inside of the parse() method.
*/

bool Parser::addNumberToTree(int num)
{
    ExprTree *expr = new ExprTreeNumber(num);
    if(bottom == nullptr && top == nullptr) {
        top = expr;
    } else if(bottom == nullptr) {
        delete expr;
        return false;
    } else {
        bottom->addRight(expr);
        bottom = nullptr;
    }
    return true;
}

void Parser::addMinusToTree()
{
    if(bottom == nullptr && top == nullptr) {
        ExprTree *expr = new ExprTreeNegation();
        bottom = expr;
        top = bottom;
    } else if(bottom == nullptr) {
        ExprTree *expr = new ExprTreeSubtraction(top);
        top = expr;
        bottom = expr;
    } else {
        ExprTree *expr = new ExprTreeNegation();
        bottom->addRight(expr);
        bottom = expr;
    }
}

void Parser::resetTree()
{
    delete top;
    top = nullptr;
    bottom = nullptr;
}