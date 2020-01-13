/*
 * BTree.h
 *
 *  Created on: Jan 13, 2020
 *      Author: f10
 */

#ifndef BTREE_H_
#define BTREE_H_

template <class T>
class Node{
	public:
		T data;
		Node<T> *left, *right;
};

template<class T>
class BTree {
	Node<T> *root;
	void insertR(Node<T>*, T);
	void displayR(Node<T>*);
	int depthR(Node<T>*);
	void inorder(Node<T>*);				// for printing inorder of tree
	Node<T>* copy(Node<T>*);			// to make a copy
public:
	BTree();
	BTree(BTree &);
	void insert(T);
	void display();
	int depth();
	void disleafs();
	virtual ~BTree();
};

#endif /* BTREE_H_ */
