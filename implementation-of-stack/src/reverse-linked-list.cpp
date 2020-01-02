//============================================================================
// Name        : reverse-linked-list.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <math.h>
#include "Stack.h"
#include "Stack.cpp"
using namespace std;
#define MAX 50

int priority(char);
char* postfixlogic(char[MAX]);
int operators(int, int, char);
int eval(char*);
char * reverse(char*);
bool checkinfix(char*);

class Expression{
	char arr[MAX];
	public:
		void toprefix();
		void topostfix();
		void evalpost();
		void evalpre();
		void enterdata();
		void display();
};

void Expression :: enterdata(){
	cout << "Enter Expression: ";
	cin.getline(arr, MAX);
}

void Expression :: evalpost(){
	cout << "\nEvaluation of Postfix is:" << eval(arr) << "\n";
}

void Expression :: evalpre(){

	char * chgArr = reverse(arr);

	cout << "\nEvaluation of Prefix is:" << eval(chgArr) << "\n";
}

void Expression :: toprefix(){
	if(checkinfix(arr)){
		char * chgArr = reverse(arr);
		chgArr = postfixlogic(chgArr);
		chgArr = reverse(chgArr);
		cout << "\nPREFIX EXPRESSION: " << chgArr;
	} else {
		cout << "ENTER VALID INFIX EXPRESSION:";
	}
}

void Expression :: topostfix(){
	if(checkinfix(arr)){
		char *postfix = postfixlogic(arr);
		cout << "POSTFIX EXPRESSION: "<< postfix;
	} else {
		cout << "ENTER VALID INFIX EXPRESSION:";
	}
}

void Expression :: display(){
	int i=0;
	while(arr[i] != '\0'){
		cout << arr[i];
		i++;
	}
}

int eval(char* arr){
	Stack<int> s;
	int i=0, val;

	while(arr[i]!='\0'){
		if(arr[i]>=48 && arr[i]<=57){
			s.push(arr[i]-48);
		} else if((arr[i] >= 65 && arr[i] <= 91) || (arr[i] >= 97 && arr[i] <= 129)){
			cout << "Enter value numeric of "<<arr[i] << ": ";
			cin >> val;
			s.push(val);
		} else if(!s.empty()) {
			s.push(operators(s.pop(), s.pop(), arr[i]));
		}
		i++;
	}
	return s.pop();
}

bool checkinfix(char * arr){
	int i=0;
	int var = 0, var2 = 0;
	Stack<char> s;
	while(arr[i]!='\0'){
		if(arr[i]==')' || arr[i]=='('){

		}
		else if((arr[i] >= 65 && arr[i] <= 91) || (arr[i] >= 97 && arr[i] <= 129)
				|| (arr[i]>=48 && arr[i]<=57 )){
			var++;
		} else {
			var2++;
		}
		i++;
	}

	if(var-1!=var2)
		return false;

	cout << "1";
	i=0;							// for "(" and ")"
	while(arr[i]!='\0'){
		if(arr[i]=='('){
			s.push(arr[i]);
		} else if(arr[i]==')') {
			if(s.empty())
				return false;
			s.pop();
		}
		i++;
	}
	cout << "2";

	if(!s.empty())
		return false;

	cout << "3";
	i=0;
	while(arr[i]!='\0'){
		i++;
	}
	i = i - 1;
	if(!(((arr[0] >= 65 && arr[0] <= 91) || (arr[0] >= 97 && arr[0] <= 129)
				|| (arr[0]>=48 && arr[0]<=57 )) && ((arr[i] >= 65 && arr[i] <= 91)
				|| (arr[i] >= 97 && arr[i] <= 129) || (arr[i]>=48 && arr[i]<=57 )))){
		return false;
	}
	cout << "4";

	return true;
}

int operators(int ope1, int ope2, char op){
	switch(op){
		case '+':
			return (ope1+ope2);
		case '-':
			return (ope1-ope2);
		case '*':
			return (ope1*ope2);
		case '/':
			return (ope1/ope2);
		case '^':
			return pow(ope1,ope2);
	}
	return 0;
}

char * reverse(char* arr){
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
	return chgArr;
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
		} else if((arr[i] >= 65 && arr[i] <= 91) || (arr[i] >= 97 && arr[i] <= 129)
				|| (arr[i]>=48 && arr[i]<=57 )){
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

void menu(){
	cout << "\n1) Convert Expression to postfix";
	cout << "\n2) Convert Expression to prefix";
	cout << "\n3) Evaluation of postfix";
	cout << "\n4) Evaluation of prefix";
	cout << "\n5) Exit";
}

int main() {

	Expression ex;

	int ch;

	while(ch!=5){

		menu();
		cout << "\nEnter Choice: ";
		cin >> ch;
		cin.ignore(1);

		if(ch!=5)
			ex.enterdata();

		switch(ch){
			case 1:
				ex.topostfix();
				break;
			case 2:
				ex.toprefix();
				break;
			case 3:
				ex.evalpost();
				break;
			case 4:
				ex.evalpre();
				break;
			case 5:
				break;
			default:
				cout << "INVALID CHOICE!";
		}
	}
	return 0;
}


/* --------------------------------------------------------------
 *
 * OUTPUT:
 *
 *
 *
 *
 *
 *
 */
