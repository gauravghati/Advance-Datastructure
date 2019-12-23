/*
 * Stack.cpp
 *
 *  Created on: Dec 16, 2019
 *      Author: f10
 */

#include <iostream>
#include "Stack.h"

template <class T>
Stack<T>::Stack() {
	top = NULL;
}

template <class T>
void Stack<T>::push(T num){
	Node<T> * p;
	p = new Node<T>;
	p->next = top;
	top = p;   //top++;
	top->data = num;	//data[top] = num;
}

template <class T>
T Stack<T>::pop(){
	T temp;
	Node<T> * tnode;
	tnode = top;
	temp = top->data;
	top = top->next;
	delete(tnode);
	return temp;
}

template <class T>
T Stack<T>::Top(){
	T data;
	data = top->data;
	return data;
}

template <class T>
bool Stack<T>::empty(){
	if(top == NULL)
		return true;
	return false;
}

template <class T>
Stack<T>::~Stack() {

}

