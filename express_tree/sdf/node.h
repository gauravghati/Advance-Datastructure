/*
 * node.h
 *
 *  Created on: 20-Jan-2020
 *      Author: f10
 */

#ifndef NODE_H_
#define NODE_H_

class node {
	private:
	char data;
	node *left,*right;
public:
	node(char x);
	friend class etree;
};

#endif /* NODE_H_ */
