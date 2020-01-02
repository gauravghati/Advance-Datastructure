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
Queue<T>::~Queue() {

}

template <class T>
void Queue<T> :: enque(T){
	Node<T> * p;
	p = new Node<T>;
	p -> next = NULL;
	rear -> next = p;
}

template <class T>
T Queue<T> :: deque(){

}
