/*
 *  Etree.cpp
 *
 *  Created on: 20-Jan-2020
 *      Author: f10
 */

#include "Etree.h"
#include <bits/stdc++.h>
using namespace std;

Node::Node(char x) {
	data=x;
	left=right=NULL;
}

// RECURSIVE TRANSVERSAL
void Etree::inorder_rec(Node *t)
{
	if(t==NULL)
		return;
	else
	{
		inorder_rec(t->left);
		cout<<t->data;
		inorder_rec(t->right);
	}
}

void Etree::postorder_rec(Node *t)
{
	if(t==NULL)
		return;
	else
	{
		postorder_rec(t->left);
		postorder_rec(t->right);
		cout<<t->data;
	}
}

void Etree::preorder_rec(Node *t){
	if(t==NULL)
		return;
	else {
		cout<<t->data;
		preorder_rec(t->left);
		preorder_rec(t->right);
	}
}

// NON-RECURSIVE ALGORITHMS
void Etree::create(string p) {
	
}

void Etree::inorder_NR(){

}

void Etree::preorder_NR() {

}

void Etree::postorder_NR() {

}

// PUBLIC FUNCTIONS OF RECURSIVE ALGOS
void Etree::inorder() {
	cout<<"Inorder Rec :: ";
	inorder_rec(root);
	cout<<endl;
}

void Etree::preorder() {
	cout<<"Preorder Rec :: ";
	preorder_rec(root);
	cout<<endl;
}

void Etree::postorder() {
	cout<<"Postorder Rec :: ";
	postorder_rec(root);
	cout<<endl;
}
