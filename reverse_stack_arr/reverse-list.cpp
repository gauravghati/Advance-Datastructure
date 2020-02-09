//============================================================================
// Name        : reverse-list.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "stack.h"
#include "stack.cpp"
using namespace std;

int main() {
	int num;
	char val;
	Stack<char> s;
	cout << "Enter number of elements in stack: ";
	cin >> num;
	for(int i=0; i<num; i++){
		cin >> val;
		s.push(val);
	}

	cout << "\nREVERSING LIST:";
	for(int i=0; i<num; i++){
		cout << s.pop() << " ";
	}

	return 0;
}
