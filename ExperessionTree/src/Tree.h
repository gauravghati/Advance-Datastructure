/*
 * Tree.h
 *
 *  Created on: Jan 20, 2020
 *      Author: f10
 */

#ifndef TREE_H_
#define TREE_H_

class Node{
public:
	char data;
	Node* left;
	Node* right;
};

class Tree {
public:
	Tree();
	void createExpreTree();
	void inorderR(Node);
	void preorderR(Node);
	void postorderR(Node);

	void inorderNR();
	void preorderNR();
	void postorderNR();

	virtual ~Tree();
};

#endif /* TREE_H_ */
