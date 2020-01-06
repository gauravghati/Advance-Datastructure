//============================================================================
// Name        : queue.cpp
// Author      : Gaurav
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Queue.cpp"
using namespace std;

int getprio(char*);

class Patient{
	char* mobileno;			// mobile no
	int pid;				// patient id
	char* bgrp;				// blood group
	int prio;				// priority
	char* name;				// name and disease
	char* disease;

	public:
		void scan();
		void display();
};

void Patient :: scan(){
	cout << "Enter Name of Person: ";
	cin.ignore();
	cin.getline(name, 20);

	cout << "Enter Disease: ";
	cin.getline(disease, 50);

	cout << "Priority";
	cin >> prio;

	cout << "Enter Patient ID: ";
	cin >> pid;
	
	cout << "Enter Mobile Number: ";
	cin.getline(mobileno, 10);

	cout << "Enter Blood Group: ";
	cin.getline(bgrp, 3);
	cin.ignore();
}

void Patient :: display(){
	
	cout << "\n<---- Patient Details: ----->";
	cout << "\nName : " << name;
	cout << "\nDisease : " << disease;
	cout << "\nPriority : " << prio;
	cout << "\nPatient ID : " << pid;
	cout << "\nMobile Number : " << mobileno;
	cout << "\nBlood Group : " << bgrp;
}

void menu(){
	cout << "\n1) Enter Patient Into Queue";
	cout << "\n2) Serve next Patient to the Doctor";
	cout << "\n3) Display List of all patient";
	cout << "\n5) Exit";
	cout << "\nEnter Choice: ";
}

int main() {

	Patient p;
	Queue<Patient> patQ;
	int val;

	menu();
	cin >> val;

	switch(val){
		case 1:
			p.scan();
			patQ.enque(p);
			cout << "\nPateint Added!";
			break;
		case 2:
			break;
		case 3:
			break;
	}

	return 0;
}
