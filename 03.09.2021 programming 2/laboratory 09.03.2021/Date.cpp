#include <iostream>
using namespace std;
#include <iomanip>
#include "date.h"

const int M = 12;	//number of months
const char* MONTH[M] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
static int dl[M] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

Date::Date() : day(9), month(3), year(2021)
{}

Date::Date(int a_day, int a_month, int a_year) : day(a_day), month(a_month), year(a_year)
{}

Date::Date(int a_day) : day(a_day), month(3), year(2021)
{}

Date::Date(int a_day, int a_month) : day(a_day), month(a_month), year(2021)
{}

Date::Date(const char* a)
{
	this->day = 10 * (a[0] - '0') + (a[1] - '0');
	this->month = 10 * (a[3] - '0') + (a[4] - '0');
	this->year = 1000 * (a[6] - '0') + 100*(a[7] - '0') + 10*(a[8]-'0') + (a[9]-'0');
}

bool& Date::SetFormat()
{
	return format;
}

ostream& operator<<(ostream& out, const Date& d)
{
	if (d.day == 0 && d.month == 0 && d.year == 0) {
		cout << "Inappropriate format of date" << endl;
	}
	else {
		if (d.format == false)
		{
			out << d.day << " " << d.month << " " << d.year;
			return out;
		}
		else
		{
			out << MONTH[d.month - 1] << " " << d.day << " " << d.year;
			return out;
		}
	}
}

istream& operator>>(istream& in, Date& d)
{
	in >> d.day >> d.month >> d.year;
	if (d.year < 2001 || d.year>2100 || d.month < 0 || d.month>12 || d.day<0) {
		d.day = 0;
		d.month = 0;
		d.year = 0;
	}
	else {
		if (d.ifLeep()) {
			if (d.month == 2) {
				if (d.day > 29) {
					d.day = 0;
					d.month = 0;
					d.year = 0;
				}
				else
					return in;
			}
			else {
				if (d.day > dl[d.month - 1]) {
					d.day = 0;
					d.month = 0;
					d.year = 0;
				}
				else
					return in;
			}
		}
		else {
			if (d.day > dl[d.month - 1]) {
				d.day = 0;
				d.month = 0;
				d.year = 0;
			}
			else
				return in;
		}
	}
}

bool Date::ifLeep() const
{
	return (year % 4 == 0 && (year % 100 != 0) || year % 400 == 0);
}

void Date::fixu()
{
	if (day == 0 && month == 0 && year == 0) {
		cout << "Inappropriate format of date" << endl;
		return;
	}
	if (ifLeep() == false) {
		a:
		if (day > dl[month - 1]) {
			day = 1;
			month += 1;
			if (month > 12) {
				month = 1;
				year += 1;
				return;
			}
			return;
		}
		else {
			return;
		}
	}
	else {
		if (month != 2) {
			goto a;
		}
		else {
			if (day > 29) {
				day = 1;
				month += 1;
				if (month > 12) {
					month = 1;
					year += 1;
					return;
				}
				return;
			}
			else {
				return;
			}
		}
	}
}

void Date::fixd()
{
	if (day == 0 && month == 0 && year == 0) {
		cout << "Inappropriate format of date" << endl;
		return;
	}
	if (ifLeep() == false) {
	a:
		if (day < 1) {
			if (month != 1){
				day = dl[month - 2];
				month -= 1;
			}
			else {
				day = dl[11];
				month = 12;
				year -= 1;
			}
			return;
		}
		else {
			return;
		}
	}
	else {
		if (month != 3) {
			goto a;
		}
		else {
			if (day < 1) {
				day = 29;
				month -= 1;
				if (month < 1) {
					month = 12;
					year -= 1;
					return;
				}
				return;
			}
			else {
				return;
			}
		}
	}
}

void Date:: NextDate()
{
	if (day == 0 && month == 0 && year == 0) {
		cout << "Inappropriate format of date" << endl;
		return;
	}
	day += 1;
	fixu();
}

void Date:: PrevDate()
{
	if (day == 0 && month == 0 && year == 0) {
		cout << "Inappropriate format of date" << endl;
		return;
	}
	day -= 1;
	fixd();
}

void Date::SelectedDay()
{
	if (day == 0 && month == 0 && year == 0) {
		cout << "Inappropriate format of date" << endl;
		return;
	}
	day += 7;
	fixu();
}

void Date::SelectedDay(int a_day)
{
	if (day == 0 && month == 0 && year == 0) {
		cout << "Inappropriate format of date" << endl;
		return;
	}
	if (a_day < 0) {
		day += a_day;
		fixd();
	}
	else {
		day += a_day;
		fixu();
	}
}

bool Date::ifEqual(Date d)
{
	if (day == 0 && month == 0 && year == 0 || (d.day == 0 && d.month == 0 && d.year == 0)) {
		cout << "Inappropriate format of date" << endl;
		return 0;
	}
	if (this->day == d.day && this->month == d.month && this->year == d.year)
		return true;
	else
		return false;
}

bool ifLess(Date d1, Date d2)
{
	if (d1.day == 0 && d1.month == 0 && d1.year == 0 || (d2.day == 0 && d2.month == 0 && d2.year == 0)) {
		cout << "Inappropriate format of date" << endl;
		return 0;
	}
	if (d1.year < d2.year)
		return true;
	if (d1.month < d2.month)
		return true;
	if (d1.day < d2.day)
		return true;
	else
		return false;
}

int NuberOfDays(Date d1, Date d2)
{
	if (d1.day == 0 && d1.month == 0 && d1.year == 0 || (d2.day == 0 && d2.month == 0 && d2.year == 0)) {
		cout << "Inappropriate format of date" << endl;
		return 0;
	}
	int count = 0;
	if (ifLess(d1, d2)) {
		while (d1.day != d2.day || d1.month != d2.month || d1.year != d2.year) {
			d1.NextDate();
			count++;
		}
	}
	else if (ifLess(d2, d1)) {
		while (d1.day != d2.day || d1.month != d2.month || d1.year != d2.year) {
			d2.NextDate();
			count++;
		}
	}
	return count;
}