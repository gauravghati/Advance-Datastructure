/*
 * stack.h
 *
 *  Created on: 20-Jan-2020
 *      Author: f10
 */

#ifndef STACK_H_
#define STACK_H_
# define max 100
#include"node.h"
class stacknode{
private:
	node * data;
	int flag;
	friend class stack;
	friend class etree;
};
class stack {
	stacknode  data[max];
	int top;
public:
	stack();
	int empty();
	int full();
	void push(stacknode  x);
	stacknode  pop();
};

#endif /* STACK_H_ */
