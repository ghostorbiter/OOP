#include <iostream>
#include "Person.h"
#include "Customer.h"
#include "staff.h"
#include "Manager.h"
#include "Boss.h"
#include "Database.h"

using namespace std;

int main()
{
	cout << "***********Task 1***********" << endl << endl;
	Customer customer1, customer2("James");
	cout << customer1 << customer2 << endl;

	cout << "***********Task 2***********" << endl << endl;
	Staff staff1, staff2("Kate");
	cout << staff1 << staff2 << endl;

	cout << "***********Task 3***********" << endl << endl;
	staff2 += customer1;
	staff2 += customer2;
	cout << staff1 << staff2;

	cout << "***********Task 4***********" << endl << endl;
	Manager manager1, manager2("Jill");
	cout << manager1 << manager2 << endl;

	cout << "***********Task 5***********" << endl << endl;
	manager2 += staff1;
	manager2 += staff2;
	cout << manager1 << manager2 << endl;

	cout << "***********Task 6***********" << endl << endl;
	Boss boss1("Bill"), boss2;
	cout << boss1 << boss2 << endl;

	cout << "***********Task 7***********" << endl << endl;
	Manager manager3, manager4;
	boss1 += manager1;
	boss1 += manager2;
	boss1 += manager3;
	boss1 += manager4;
	cout << boss1;

	cout << "***********Task 8***********" << endl << endl;
	boss1.work(customer2);

	cout << "***********Task 9***********" << endl << endl;
	boss1.general_info();

	cout << "***********Task 10***********" << endl << endl;
	Database database;
	cout << database << endl;

	cout << "***********Task 11***********" << endl << endl;
	database.add(manager2);
	database.add(staff2);
	database.add(customer2);
	database.add(customer1);
	database.add(manager1);
	cout << database << endl;

	cout << "***********Task 12***********" << endl << endl;
	database.say_all_customers();
	cout << endl;
	database.say_all_managers();
	cout << endl;
	database.say_all_staff();
	cout << endl;

	return 0;
}