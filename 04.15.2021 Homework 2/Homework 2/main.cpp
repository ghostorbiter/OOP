#include <iostream>
using namespace std;
#include "account.h"
#include "shop.h"
#include "basket.h"

int main()
{
	//...............SHOP PART...............//

	cout << endl;

	//S.1
	Shop cloth1;
	Shop cloth2(38, 12.5);
	Shop cloth3(42, 15, "Gucci");
	Shop cloth4(40, 14.3, "Nike", Gender::male, Type::shoes);

	cout << cloth1 << cloth2 << cloth3 << cloth4 << endl;
	
	//S.2
	cloth1.check_availability();
	cloth1.change_availability() = true;
	cloth1.check_availability();
	cloth1.change_availability() = false;

	//...............BASKET PART...............//

	cout << endl << endl;

	//B.1
	Cart cart1;
	cout << cart1 << endl;

	//B.2
	cart1 += cloth1;
	cart1 += cloth2;
	cart1 += cloth3;
	cart1 += cloth4;
	cart1 += cloth2;
	cout << cart1 << endl;

	//B.3
	cart1 -= cloth2;
	cout << cart1 << endl;

	//B.4
	Cart cart2;
	cout << cart2 << endl;
	cart2 = cart1;
	cout << cart2 << endl;
	cart2.clear();
	cout << cart2 << endl;

	//B.5
	cart1.filter(5);
	cout << endl;
	cart1.filter(Type::shoes);
	cout << endl;
	cart1.filter(Gender::everygender);
	cout << endl;

	//...............ACCOUNT PART...............//

	cout << endl << endl;

	//A.1
	Account account1;
	Account account2("Yuldashbek", "yuldash.coded.this@gmail.com");
	Account account3("Michael", "michael.no.name@gmail.com", 5648);
	cout << account1 << account2 << account3 << endl;

	//A.2
	Account account4("James", "yuldash.coded.this@gmail.com");
	cout << account4 << endl;

	//A.3
	account1.Add_Cash(500);
	account2.Add_Cash(1500);
	account3.Add_Cash(200);
	account4.Add_Cash(10);

	cout << endl;

	account2.Add_credit_card(8080);
	account2.Add_Cash(20);

	//A.4
	account1.Change_name("Tom");
	account3.Change_name("James");
	cout << account1 << account3 << endl;

	account1.Change_mail("new.mail@gmail.com");
	account1.Change_name("Tom");

	account2.Change_mail("michael.no.name@gmail.com");
	account2.Change_mail("hello.there@gmail.com");
	Account account5("Jennie", "yuldash.coded.this@gmail.com");
	cout << endl << account1 << account2 << account3 << account4 << account5 << endl;

	//A.5
	account1.my_cart += cloth2;
	account1.my_cart += cloth2;
	account1.my_cart += cloth3;

	account2.my_cart += cloth2;
	account2.my_cart += cloth4;
	account2.my_cart += cloth3;

	account4.my_cart += cloth4;
	account4.my_cart += cloth2;
	account4.my_cart += cloth3;
	account4.my_cart += cloth3;

	account5.my_cart += cloth4;
	account5.my_cart += cloth2;
	account5.my_cart += cloth4;
	account5.my_cart += cloth2;
	account5.my_cart += cloth3;

	cout << account1.my_cart << endl;
	cout << account2.my_cart << endl;
	cout << account4.my_cart << endl;
	cout << account5.my_cart << endl;

	//A.6
	Account account6;

	account6.buy(0);

	account1.buy(4);
	account1.buy(3);
	account1.buy(2);

	account2.buy(1);

	account4.buy(1);
	account4.buy(2);

	account5.buy(0);
	account5.buy(1);

	cout << endl;
	cout << account1.my_cart << endl;
	cout << account2.my_cart << endl;
	cout << account4.my_cart << endl;
	cout << account5.my_cart << endl;

	cout << "THE END" << endl;

	delete[] all_mails;

	return 0;
}