#pragma once
#include <iostream> 
using namespace std;
#include <iomanip>
#include <string>

class article
{
protected:
	string name;

public:
	article(string name) : name(name) {}
	virtual ~article() {}
	virtual double value() const = 0;
	virtual double get_price() const = 0;
	virtual ostream& info(ostream& out) const = 0;
	friend ostream& operator<<(ostream& out, const article& a);
};


class article_per_item : public article
{
protected:
	double price_per_item;

public:
	// implement
	article_per_item(string name, double price) : article(name), price_per_item(price) {}
	double value() const override;
	double get_price() const override;
	ostream& info(ostream& out) const override;

};


class article_per_kilo : public article
{
protected:
	double price_per_kilo;
	double weight;

public:
	// implement
	article_per_kilo(string name, double price_kilo, double _weight) : article(name), price_per_kilo(price_kilo), weight(_weight) {}
	double value() const override;
	double get_price() const override;
	ostream& info(ostream& out) const override;
};


