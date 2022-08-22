#include <iostream> 
using namespace std;
#include <iomanip>
#include <string>
#include "article.h"


ostream& operator<<(ostream& out, const article& a)
{
	a.info(out);
	return out;
}


// implement

double article_per_item::value() const
{
	return price_per_item;
}

double article_per_item::get_price() const
{
	return price_per_item;
}


ostream& article_per_item::info(ostream& out) const
{
	out << "Article Name: " << name << " Price: " << price_per_item << endl;
	return out;
}


double article_per_kilo::value() const
{
	return price_per_kilo * weight;
}

double article_per_kilo::get_price() const
{
	return price_per_kilo;
}

ostream& article_per_kilo::info(ostream& out) const
{
	out << "Article Name: " << name << "(weight: " << weight << ") Price (per kg): " << price_per_kilo << " Price (" << weight << " kg): " << value() << endl;
	return out;
}