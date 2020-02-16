/*
 *  Etree.cpp
 *
 *  Created on: 20-Jan-2020
 *      Author: f10
 */

#ifndef ETREE_H_
#define ETREE_H_

class Node {
private:
	char data;
	Node *left,*right;
public:
	Node(char x);
	friend class Etree;
};

class stacknode{
private:
	Node *data;
	int flag;
	friend class Etree;
};

class Etree {
	Node * root;
	void inorder_rec(Node*);
	void preorder_rec(Node*);
	void postorder_rec(Node*);

public:
	void create(string p);
	void inorder();
	void preorder();
	void postorder();
	void preorder_nr();
	void inorder_nr();
	void postorder_nr();
};

#endif /* ETREE_H_ */