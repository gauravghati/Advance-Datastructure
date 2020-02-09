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
	T data;
	Node<T> *left, *right;

	public:
		template <class U> 
		friend class BTree;
};

template<class T>
class BTree {
	Node<T> *root;
	Node<T>* insertR(Node<T>*, T);
	int depthR(Node<T>*);
	void inorder(Node<T>*);				// for printing inorder of tree
	void preorder(Node<T>*);
	void postorder(Node<T>*);
	Node<T>* copy(Node<T>*, Node<T>*);			// to make a copy
	void display(Node<T>*, int);

public:
	BTree();
	BTree(const BTree&);
	void create();						// create tree
	void insert(T);						// insert single node
	void displaytree();					// for tree structure
	int depth();						// depth of the tree
	void disleafs();					// for leaf node
	virtual ~BTree();

};

#endif /* BTREE_H_ */
