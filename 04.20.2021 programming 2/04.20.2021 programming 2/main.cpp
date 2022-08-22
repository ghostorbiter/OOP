#include <iostream>
#include "MyText.h" 
#include "MyStack.h"

using namespace std;

int main ()
{
	// ----- Part 1 -----
	/*cout<<"----- Part 1 -----"<<endl;

	MyText* ps;
	{
		MyText s1;
		cout<<"Sentence 1 : "<<s1<<endl;

		MyText s2("The drone on Mars.");
		cout<<"Sentence 2 : " <<s2<<endl;

		MyText s3(s2);
		cout<<"Sentence 3 : " <<s2<<endl;
		
		s1 = s2;
		cout<<"Sentence 1 = Sentence 2 : " <<s1<<endl;
		
		ps = new MyText("C++ is fun!");

		s1 = *ps;
		cout << "PS : " << s1 << endl;

	}*/

	
	// ----- Part 2 -----
	cout<<endl<<"----- Part 2 -----"<<endl;
	/*
	
		MyStack mst; 
		MyStack nst = MyStack(3); 
		MyStack cst(nst); 
		mst = cst;
	*/
	cout<<"After stack test"<<endl;

	MyText s1;
	MyText s2("To be, or not to be.");
	
	MyStack ms(4);

	ms.push(s2); 
	ms.push(MyText("What is your name?")); 
	ms.push(s1); 
	ms.push(MyText("Good luck!"));
	
	MyStack mscpy(ms);
	cout<<endl<<"Pop copy:"<<endl;
	while( !mscpy.isEmpty() ){
		cout<< mscpy.pop() << endl;
	}
	cout<<"---"<<endl;

	mscpy = MyStack();
	cout<<endl<<"Write in console 3 lines of text (79 characters max):"<<endl;
	while (mscpy.getSize() < 3 ) {
		char line[80];
		cin.getline(line,79);
		mscpy.push(MyText(line));
	}
	
	cout<<"--- Size = "<< mscpy.getSize() << endl;
	ms = mscpy;

	cout<<endl<<"Pop your sentences:"<<endl;
	while( !mscpy.isEmpty() ){
		cout<< mscpy.pop() << endl;
	} 

	
	// ----- Part 3 -----
	/*cout<<endl<<"----- Part 3 -----"<<endl;
	ms = ms.sort();

	cout<<endl<<"Pop your sentences sorted:"<<endl;
	while( !ms.isEmpty() ){
		cout<< ms.pop() << endl;
	} */

	cout<<"\nBye"<<endl;
	//system("pause");
}
