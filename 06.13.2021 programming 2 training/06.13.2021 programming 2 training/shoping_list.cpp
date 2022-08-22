#include <iostream> 
using namespace std;
#include <fstream>
#include <algorithm>
#include <numeric>
#include "shoping_list.h"
#include "article.h"

// implement

//bool isPerKilo(article* a) 
//{
//	if (dynamic_cast<article_per_kilo*>(a))
//		return true;
//	return false;
//}

shoping_list::shoping_list() {}

shoping_list::~shoping_list()
{
	for (auto& i : articles)
		delete i;
}

void shoping_list::add_article(article* art)
{
	articles.push_back(art);
}

void shoping_list::sort_list()
{
	auto it = [](article* article1, article* article2) {
		return article1->get_price() < article2->get_price();
	};

	articles.sort(it);
}


ostream& operator<<(ostream& out, const class shoping_list& sl)
{
	auto print = [&out](const article* art) {
		art->info(out);
	};

	for_each(sl.articles.begin(), sl.articles.end(), print);
	return out;
}

double shoping_list::sum_list() const
{
	auto it = [](double sum, article* art) {
		return sum+art->value();
	};

	return accumulate(articles.begin(), articles.end(), 0.0, it);
}

article* shoping_list::max_value() const
{
	auto it = [](const article* art1, const article* art2) { return art1->value() < art2->value(); };
	auto max_elem = max_element(articles.begin(), articles.end(), it);
	return *max_elem;
}

int shoping_list::count_more_expansive(double value) const
{
	auto it = [value](const article* art) {return art->value() > value; };
	return count_if(articles.begin(), articles.end(), it);
}

void shoping_list::save_list(string shoping_list_file) const
{
	ofstream out(shoping_list_file);

	if (!out) {
		cout << "Error: no file" << endl;
		return;
	}

	out << *this;
	out.close();
}

//shoping_list::