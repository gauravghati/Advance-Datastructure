/*
 * Queue.cpp
 *
 *  Created on: Jan 2, 2020
 *      Author: f10
 */

#include "Queue.h"
# include <iostream>
using namespace std;

template <class T>
Queue<T>::Queue() {
	front = NULL;
	rear = NULL;
}

template <class T>
void Queue<T> :: enque(T var){
	Node<T> * p;
	p = new Node<T>;
	p -> data = var;
	p -> next = NULL;
	rear -> next = p;
}

template <class T>
T Queue<T> :: deque(int index){
	Node<T> *temp, *prev;
	T data;
	temp = front;

	while(index!=0) {
		prev = temp;
		temp = temp -> next;
		index--;
	}

	data = temp->data;
	prev->next = temp->next;
	delete(temp);

	return data;
}

template <class T>
Queue<T>::~Queue() {

}
