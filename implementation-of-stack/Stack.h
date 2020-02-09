/*
 * Stack.h
 *
 *  Created on: Dec 16, 2019
 *      Author: f10
 */

#ifndef STACK_H_
#define STACK_H_

template <class T>
class Node{
	public:
		T data;
		Node * next;
};

template <class T>
class Stack{
	Node<T> *top;
public:
	Stack();
	void push(T);
	T pop();
	T Top();
	bool empty();
	virtual ~Stack();
};

#endif /* STACK_H_ */
