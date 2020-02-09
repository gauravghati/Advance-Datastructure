/*
 * stack.h
 *
 *  Created on: Dec 16, 2019
 *      Author: f10
 */

#ifndef STACK_H_
#define STACK_H_
#define MAX 50

template <class T>
class Stack{
	T data[MAX];
	int top;
public:
	Stack();
	void push(T);
	T pop();
	virtual ~Stack();
};

#endif /* STACK_H_ */
