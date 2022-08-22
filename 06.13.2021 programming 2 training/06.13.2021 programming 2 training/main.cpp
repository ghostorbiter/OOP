#include <iostream>
using namespace std;
#include <string>
#include "article.h"
#include "shoping_list.h"

//----------------------------------------------------------------
int main()
{
	cout << " **************************** Part 1 **************************** " << endl;
	
	article_per_item milk("Milk", 3.20);
	article_per_kilo carrot("Carrot", 1.20, 0.70);

	cout << milk << carrot << endl;
	

	cout << " **************************** Part 2 **************************** " << endl;
	
	shoping_list sth_to_buy;

	sth_to_buy.add_article(new article_per_item("Milk", 3.20));
	sth_to_buy.add_article(new article_per_kilo("Carrot", 1.20, 0.70));
	sth_to_buy.add_article(new article_per_item("Chocolate", 7.90));
	sth_to_buy.add_article(new article_per_kilo("Tomatos", 5.40, 1.50));
	sth_to_buy.add_article(new article_per_item("Bread", 3.50));
	sth_to_buy.add_article(new article_per_kilo("Potatoes", 3.40, 2.50));

	cout << "List of articles: " << endl;
	cout << sth_to_buy << endl;
	
	cout << " **************************** Part 3 **************************** " << endl;
	
	sth_to_buy.sort_list();

	cout << "Sorted list of articles: " << endl;
	cout << sth_to_buy << endl;
	
	cout << " **************************** Part 4 **************************** " << endl;
	
	cout << "Total value of all articles in list: " << sth_to_buy.sum_list() << endl << endl;
	
	cout << " **************************** Part 5 **************************** " << endl;
	
	cout << "Article with max value (more expensive one) in list: " << endl;
	cout << *sth_to_buy.max_value() << endl;
	
	cout << " **************************** Part 6 **************************** " << endl;
	
	cout << "Articles more expansive than 4.0 : " << sth_to_buy.count_more_expansive(4.0) << endl << endl;
	
	cout << " **************************** Part 7 **************************** " << endl;
	
	sth_to_buy.save_list("shoping_list.txt");
	cout << "Check whether file shoping_list.txt exist and is correct!" << endl;
	
}
//-----------------------------------------------------------------
