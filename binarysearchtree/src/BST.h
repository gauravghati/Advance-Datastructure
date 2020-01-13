/*
 * BST.h
 *
 *  Created on: Jan 13, 2020
 *      Author: f10
 */

#ifndef BST_H_
#define BST_H_

template <class T>
class Node{
	public:
		T data;
		Node<T> *left, *right;
};

template <class T>
class BST {

	Node<T> *root;
	void insertR(Node<T>*, T);
	void displayR(Node<T>*);
	int depthR(Node<T>*);
	void inorder(Node<T>*);				// for printing inorder of tree
	Node<T>* copy(Node<T>*);			// to make a copy

	public:
		BST();
		BST(BST &);
		void insert(T);
		void display();
		int depth();
		void disleafs();
		virtual ~BST();
};

#endif
