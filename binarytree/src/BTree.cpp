/*
 * BTree.cpp
 *
 *  Created on: Jan 13, 2020
 *      Author: f10
 */

#include "BTree.h"
#include <iostream>

template <class T>
BTree<T>::BTree() {
	root = NULL;
}

template <class T>
BTree<T>::~BTree() {

}

// Recursion Private Functions
template<class T>
Node<T>* BTree<T>::insertR(Node<T>* temp, T key){
	char var;

	if(temp==NULL){
		Node<T> *p = new Node<T>;
		p->data = key;
		return p;
	}
	do{
		std :: cout << "\nEnter L/R for Left Insert or Right Insert of " << (temp->data) <<": ";
		std :: cin >> var;
	} while(var!='L' && var!='l' && var!='r' && var!='R');

	if(var == 'l' || var == 'L'){
		temp->left = insertR(temp->left, key);
	} else {
		temp->right = insertR(temp->right, key);
	}
	return temp;
}

template<class T>
void BTree<T>::displayR(Node<T>* root){

}

template<class T>
void BTree<T>::inorder(Node<T>* root){

}

template<class T>
int BTree<T>::depthR(Node<T>* root){
	return 0;
}

template<class T>
Node<T>* BTree<T>::copy(Node<T>* root){

}


// Calling Public Functions
template<class T>
void BTree<T> :: operator=(BTree<T> & root){

}

template<class T>
void BTree<T>::insert(T key){
	root = insertR(root, key);
}

template<class T>
void BTree<T>::display(){

}

template<class T>
int BTree<T>::depth(){
	return 0;
}

template<class T>
void BTree<T>::disleafs(){

}
