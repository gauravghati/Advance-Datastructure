//============================================================================
// Name        : reverse-linked-list.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "Stack.h"
#include "Stack.cpp"
using namespace std;
#define MAX 50

int priority(char);
char* postfixlogic(char[MAX]);

class Expression{
	char arr[MAX];
	public:
		void toprefix();
		void topostfix();
		void enterdata();
		void display();
};

void Expression :: toprefix(){
	Stack<char> s;
	int i=0;
	char* chgArr = new char[MAX];

	while(arr[i]!='\0'){
		s.push(arr[i]);
		i++;
	}

	i=0;
	while(!s.empty()){
		chgArr[i] = s.pop();
		i++;
	}

	i=0;
	while(chgArr[i] != '\0'){
		if(chgArr[i]=='(')
			chgArr[i] = ')';
		else if(chgArr[i]==')')
			chgArr[i] = '(';
		i++;
	}

	chgArr = postfixlogic(chgArr);

	i=0;
	while(chgArr[i]!='\0'){
		s.push(chgArr[i]);
		i++;
	}

	i=0;
	while(!s.empty()){
		chgArr[i] = s.pop();
		i++;
	}

    cout << "\nPREFIX EXPRESSION: " << chgArr;
}

void Expression :: display(){
	int i=0;
	while(arr[i] != '\0'){
		cout << arr[i];
		i++;
	}
}

void Expression :: topostfix(){
	char *postfix = postfixlogic(arr);

    int	i=0;
    cout << "POSTFIX EXPRESSION: "<< postfix;
}

char* postfixlogic(char* arr){

	Stack<char> s;
	char * postfix = new char[MAX];
	int i=0, j=0;

	while(arr[i]!='\0'){
		if(arr[i] == '('){
			s.push(arr[i]);
		} else if (arr[i]==')'){
			while(s.Top()!='('){
				postfix[j] = s.pop();
				j++;
			}
			s.pop();
		} else if((arr[i] >= 65 && arr[i] <= 91) || (arr[i] >= 97 && arr[i] <= 129)){
			postfix[j] = arr[i];
			j++;
		}
		else{
			 while(!s.empty() && priority(s.Top()) >= priority(arr[i])){
				postfix[j] = s.pop();
				j++;
			 }
			 s.push(arr[i]);
		}
		i++;
	}

	while(!s.empty()){
		postfix[j] = s.pop();
		j++;
	}

	return postfix;
}

int priority(char a){
	switch(a){
		case '(':
			return 1;

		case ')':
			return 2;

		case '+':
		case '-':
			return 3;

		case '*':
		case '/':
			return 4;

		case '^':
			return 5;
	}
	return 0;
}

void Expression :: enterdata(){
	cout << "Enter Infix String: ";
	cin.getline(arr, MAX);
}

void menu(){
	cout << "1) Enter Infix Expression";
	cout << "2) Convert Expression to postfix";
	cout << "3) Convert Expression to prefix";
	cout << "4) Evaluation of postfix";
	cout << "5) Evaluation of prefix";
	cout << "6) Exit";
}

int main() {

	Expression ex;
	ex.enterdata();
	ex.topostfix();
	ex.toprefix();

	return 0;
}