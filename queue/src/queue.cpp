//============================================================================
// Name        : queue.cpp
// Author      : Gaurav
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Patient{
	char* mobileno;			// mobile no
	int pid;				// patient id
	char* bgrp;				// blood grop
	int prio;				// prio
	char* name;				// name and disease
	char* disease;

	public:
		void scan();
		Patient next_pat();
		void display();
};

void Patient :: scan(){
	
}

void Patient :: display(){
	
}

void Patient :: next_pat(){
	
}

int main() {


	return 0;
}
