#pragma once
#include <iostream> 
using namespace std;
#include <list>
#include "article.h"

class shoping_list
{
	list<article*> articles;
public:
	shoping_list();
	~shoping_list();
	void add_article(article* art);
	void sort_list();
	double sum_list() const;
	article* max_value() const;
	int count_more_expansive(double value) const;
	void save_list(string shoping_list_file) const;
	friend ostream& operator<<(ostream& out, const class shoping_list& sl);
};




