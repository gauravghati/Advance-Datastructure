/*
=========================================================================
Assignment : EXPRESSION TREE
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Problem Statement:
	Construct and expression tree from postfix/prefix expression and perform recursive
	and non- recursive In-order, pre-order and post-order traversals.
=========================================================================
*/

#include<iostream>
using namespace std;
#include"Etree.cpp"

int main() {
	Etree obj;
	string s;
	cout<<"Enter postfix expression.\n";
	getline(cin,s);
	
	obj.create(s);
	obj.inorder();
	obj.preorder();
	obj.postorder();
	obj.inorder_NR();
	obj.preorder_NR();
	obj.postorder_NR();
}
