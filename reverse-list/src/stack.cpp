/*
 * stack.cpp
 *
 *  Created on: Dec 16, 2019
 *      Author: f10
 */

#include <iostream>

using namespace std;
#include "stack.h"

template <class T>
Stack<T>::Stack() {
	top = 0;
}

template <class T>
void Stack<T>::push(T num){
	if(top>=MAX){
		cout<< "stack Overflow";
		return;
	}
	top++;
	data[top] = num;
}

template <class T>
T Stack<T>::pop(){
	if(top>0){
		top--;
		return data[top+1];
	}
	cout << "stack Empty";
	return -1;
}

template <class T>
Stack<T>::~Stack() {

}

