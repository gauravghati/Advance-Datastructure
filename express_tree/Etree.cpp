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
	int i=0;
	stack<Node> s;
	stacknode sn;
	Node * t = NULL;
	while(p[i]!='\0')
	{
		if((p[i] > 47 && p[i] < 58) || (p[i] > 64 && p[i] < 91) || (p[i] > 96 && p[i] < 123)){
			t=new Node(p[i]);
			sn.data=t;
			s.push(sn);
		} else {
			t=new node(p[i]);
			sn = s.pop();
			t->right=sn.data;
			sn = s.pop();
			t->left=sn.data;
			sn.data = t;
			s.push(sn);
		}
		i++;
	}
	sn=s.pop();
	root=sn.data;
}

void Etree::inorder_NR(){
	stack<Node> s;
	stacknode sn;
	node *t = root;
	cout<<"Inorder Non_Rec :: ";
	while(t!=NULL){
		sn.data = t;
		s.push(sn);
		t = t->left;
	}
	while(!s.empty()) {
		sn = s.pop();
		t = sn.data;
		cout << t->data;
		t = t -> right;
		while(t!=NULL){
			sn.data = t;
			s.push(sn);
			t = t->left;
		}
	}
	cout<<endl;
}

void Etree::preorder_NR() {
	stack<Node> s;
	stacknode sn;
	node *t = root;
	cout<<"Preorder Non_Rec :: ";
	while(t != NULL){
		cout << t->data;
		sn.data = t;
		s.push(sn);
		t = t->left;
	}
	while(!s.empty()){
		sn=s.pop();
		t = sn.data;
		t = t->right;
		while(t!=NULL){
			cout << t -> data;
			sn.data = t;
			s.push(sn);
			t = t -> left;
		}
	}
	cout<<endl;
}

void Etree::postorder_NR() {
	cout<<"Postorder Non_Rec :: ";
	stack<Node> s;
	stacknode sn;
	node * t=root;
	while(t!=NULL) {
		sn.data = t;
		sn.flag = 0;
		s.push(sn);
		t = t->left;
	}
	while(!s.empty()){
		sn = s.pop();
		t = sn.data;
		if(sn.flag==0) {
			sn.flag=1;
			s.push(sn);
			t = t->right;
			while(t!=NULL)
			{
				sn.data = t;
				sn.flag = 0;
				s.push(sn);
				t = t->left;
			}
		} else {
			cout << t->data;
		}
		
	}
	cout<<endl;
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
