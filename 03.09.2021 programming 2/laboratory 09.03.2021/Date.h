#pragma once

class Date
{
	int day ;
	int month;
	int year;

	bool format = false;

	bool ifLeep() const;

public:
	Date();
	Date(int a_day, int a_month, int a_year);
	Date(int a_day);
	Date(int a_day, int a_month);
	Date(const char* a);

	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

	bool& SetFormat();

	void fixu();
	void fixd();

	void NextDate();
	void PrevDate();

	void SelectedDay();
	void SelectedDay(int a_day);

	bool ifEqual(Date d);
	friend bool ifLess(Date d1, Date d2);
	friend int NuberOfDays(Date d1, Date d2);
};



