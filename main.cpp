#include <iostream>
#include "mychainedstack.h"
using namespace std;

// Basic Stack test procedure
int main()
{
 	cout << "Stacktest v1.0\n";
	Mychainedstack *mystack = new Mychainedstack();
	mystack->push(1);
	mystack->push(24);
	mystack->push(98);
	int tmp; 
	tmp = mystack->pop();
	tmp = mystack->pop();	
	cout << tmp << "\n";
	mystack->push(51);
	mystack->push(63);
	Mychainedstack *appendstack = *mystack + *mystack;
	tmp = appendstack->pop(); 
	tmp = appendstack->pop(); 
	cout << tmp << "\n";	

	mystack->clear();
	tmp = appendstack->pop(); 
        cout << tmp << "\n";

	// + test de fuite memoire

  	return 0;
}
