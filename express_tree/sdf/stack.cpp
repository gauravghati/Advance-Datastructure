/*
 * stack.cpp
 *
 *  Created on: 20-Jan-2020
 *      Author: f10
 */

#include "stack.h"
#include <iostream>
using namespace std;
stack::stack() {
	top=-1;

}
int stack::empty()
{
	if(top==-1)
		return 1;
	return 0;
}
int stack::full()
{
	if(top==100)
			return 1;
		return 0;
}
void stack::push(stacknode  x)
{
	if(!full())
	{
		top++;
		data[top]=x;
	}
}
stacknode  stack::pop()
{
	stacknode t;
	if(!empty())
	{
		t=data[top];
		top--;
	}
	return t;
}
