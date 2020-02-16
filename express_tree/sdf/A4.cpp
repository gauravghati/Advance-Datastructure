//============================================================================
// Name        : 4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;
#include"node.cpp"
#include"stack.cpp"
class etree
{
	node * root;
public:
	void create(string p);
	void inorder();
	void inorder_rec(node * t);
	void preorder();
	void preorder_rec(node * t);
	void postorder();
	void postorder_rec(node * t);
	void preorder_NR();
	void inorder_NR();
	void postorder_NR();
};
void etree::create(string p)
{
	int i=0;
	stack s;
	stacknode sn;
	node * t=NULL;
	while(p[i]!='\0')
	{
		if((p[i]>47&&p[i]<58)||(p[i]>64&&p[i]<91)||(p[i]>96&&p[i]<123))
		{
			t=new node(p[i]);
			sn.data=t;
			s.push(sn);
		}
		else
		{
			t=new node(p[i]);
			sn=s.pop();
			t->right=sn.data;
			sn=s.pop();
			t->left=sn.data;
			sn.data=t;
			s.push(sn);
		}
		i++;
	}
	sn=s.pop();
	root=sn.data;
}
void etree::inorder()
{
	cout<<"Inorder Rec :: ";
	inorder_rec(root);
	cout<<endl;
}
void etree::inorder_rec(node *t)
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
void etree::preorder()
{
	cout<<"Preorder Rec :: ";
	preorder_rec(root);
	cout<<endl;
}
void etree::preorder_rec(node *t)
{
	if(t==NULL)
		return;
	else
	{
		cout<<t->data;
		preorder_rec(t->left);
		preorder_rec(t->right);
	}
}
void etree::postorder()
{
	cout<<"Postorder Rec :: ";
	postorder_rec(root);
	cout<<endl;
}
void etree::postorder_rec(node *t)
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
void etree::inorder_NR()
{
	stack s;
	stacknode sn;
	node *t=root;
	cout<<"Inorder Non_Rec :: ";
	while(t!=NULL)
	{
		sn.data=t;
		s.push(sn);
		t=t->left;
	}
	while(!s.empty())
	{
		sn=s.pop();
		t=sn.data;
		cout<<t->data;
		t=t->right;
		while(t!=NULL)
		{
			sn.data=t;
			s.push(sn);
			t=t->left;
		}
	}
	cout<<endl;
}
void etree::preorder_NR()
{
	stack s;
	stacknode sn;
	node *t=root;
	cout<<"Preorder Non_Rec :: ";
	while(t!=NULL)
	{
		cout<<t->data;
		sn.data=t;
		s.push(sn);
		t=t->left;
	}
	while(!s.empty())
	{
		sn=s.pop();
		t=sn.data;
		t=t->right;
		while(t!=NULL)
		{
			cout<<t->data;
			sn.data=t;
			s.push(sn);
			t=t->left;
		}
	}
	cout<<endl;
}
void etree::postorder_NR()
{
	cout<<"Postorder Non_Rec :: ";
	stack s;
	stacknode sn;
	node * t=root;
	while(t!=NULL)
	{
		sn.data=t;
		sn.flag=0;
		s.push(sn);
		t=t->left;
	}
	while(!s.empty())
	{
		sn=s.pop();
		t=sn.data;
		if(sn.flag==0)
		{
			sn.flag=1;
			s.push(sn);
			t=t->right;
			while(t!=NULL)
			{
				sn.data=t;
				sn.flag=0;
				s.push(sn);
				t=t->left;
			}
		}
		else
		{
			cout<<t->data;
		}
		
	}
	cout<<endl;
}
int main() {
	etree obj;
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
