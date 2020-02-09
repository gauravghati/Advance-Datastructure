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
	
	if(front==NULL){
		front = p;
		rear = p;
	} else {
		rear -> next = p;
		rear = rear -> next;
	}
}

template <class T>
void Queue<T> :: printQ(){
	Node<T> *temp = front;
	while(temp != NULL){
		cout << (temp->data);
		temp = temp->next;
	}
}

template <class T>
T Queue<T> :: deque(int index){
	Node<T> *temp, *prev;
	T data;
	temp = front;

	data = temp->data;
	index = index - 1;

	if(index==0){
		front = temp->next;
		delete(temp);
		return data;
	}

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
int Queue<T>:: size() {
	int s = 0;
	Node<T> *temp = front;

	while(temp!=NULL){
		s++;
		temp = temp -> next;
	}
	return s;
}

template <class T>
T Queue<T> :: getele(int index){
	Node<T> *temp = front;
	index--;
	while(index--){
		temp = temp->next;
	}
	return temp->data;
}

template <class T>
Queue<T>::~Queue() {
	
}