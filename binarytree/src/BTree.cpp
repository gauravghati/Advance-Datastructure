/*
 * BTree.cpp
 *
 *  Created on: Jan 13, 2020
 *      Author: f10
 */

#include "BTree.h"
#include <iostream>
using namespace std;

template <class T>
BTree<T>::BTree() {
	root = NULL;
}

template <class T>
BTree<T>::~BTree() {

}

// Recursion Private Functions
template<class T>		
Node<T>* BTree<T>::insertR(Node<T>* temp, T key){			// DONE
	char var;

	if(temp==NULL){
		Node<T> *p = new Node<T>;
		p->data = key;
		return p;
	} do {
		cout << "\nEnter L/R for Left Insert or Right Insert of " << (temp->data) <<": ";
		cin >> var;
	} while(var!='L' && var!='l' && var!='r' && var!='R');

	if(var == 'l' || var == 'L'){
		temp->left = insertR(temp->left, key);
	} else {
		temp->right = insertR(temp->right, key);
	}
	return temp;
}

template<class T>
void BTree<T>::inorder(Node<T>* mroot){					// DONE
	if(mroot != NULL){
		inorder(mroot->left);
		cout << " " << mroot->data;
		inorder(mroot->right);
	}
}

template<class T>
void BTree<T>::preorder(Node<T>* mroot){					// DONE
	if(mroot != NULL){
		cout << " " << mroot->data;
		preorder(mroot->left);
		preorder(mroot->right);
	}
}

template<class T>
void BTree<T>::postorder(Node<T>* mroot){				// DONE
	if(mroot != NULL){
		postorder(mroot->left);
		postorder(mroot->right);
		cout << " " << mroot->data;
	}
}

template<class T>
int BTree<T>::depthR(Node<T>* mroot){					// DONE
	if(mroot == NULL)
		return 0;
	else {
		int rdepth = depthR(mroot->right);
		int ldepth = depthR(mroot->left);

		if(rdepth > ldepth)
			return (rdepth + 1);
		else
			return (ldepth + 1);
	}
}

template<class T>
void BTree<T>::display(Node<T>* mroot, int space){		// reverse Inorder  // DONE
	if(mroot == NULL)
		return;

	space += 10;

	display(mroot->right, space);						// rightmost child
	cout << "\n";

	for(int i=10; i<space; i++)
		cout << " ";									// for spaces
	cout << mroot->data << "\n";

	display(mroot->left, space);							// left child
}

template <class T>
Node<T>* BTree<T>::copy(Node<T>* copiedTreeRoot, Node<T>* mainTreeRoot){
    if (mainTreeRoot == NULL)
        copiedTreeRoot = NULL;
    else{
        copiedTreeRoot = new Node<T>;
        copiedTreeRoot->data = mainTreeRoot->data;
        copyTree(copiedTreeRoot->left, mainTreeRoot->left);
        copyTree(copiedTreeRoot->right, mainTreeRoot->right);
    }
    return copiedTreeRoot;
} 

// Calling Public Functions
template<class T>
BTree<T> :: BTree(const BTree<T> &var1){
	root = copy(root, var1->root);
}

template<class T>
void BTree<T>::insert(T key){
	root = insertR(root, key);
}

template<class T>
void BTree<T>::disleafs(){								//DONE
	cout << "\n1) Inorder Display: ";
	cout << "\n2) Preorder Display: ";
	cout << "\n3) Postorder Display: ";
	cout << "\n Enter Choice: ";
	int val;
	cin >> val;

	switch(val){
		case 1:
			inorder(root);
			cout << "\n";
			break;
		case 2: 
			preorder(root); 
			cout << "\n";
			break;
		case 3:
			cout << "\n";
			postorder(root); 
			break;
		default:
			cout << "Enter Valid Number";
	}
}

template<class T>									// DONE
int BTree<T>::depth(){
	return (depthR(root));
}

template<class T>
void BTree<T>::displaytree(){						// DONE
	cout << "<-------------TREE STRUCTURE------------->";
	display(root, 0);
}

template<class T>
void BTree<T>::create(){
	int n = 0, val;
	cout << "\nEnter Number of Elements: ";
	cin >> n;

	for(int i=0; i<n; i++){
		cout << "ENter the Value to be Inserted: ";
		cin >> val;
		insert(val);
	}
}