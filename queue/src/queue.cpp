//============================================================================
// Name        : queue.cpp
// Author      : Gaurav
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Queue.cpp"
#include <string.h>
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
		Patient();
		void scan();
		friend ostream & operator<<(ostream & Str, Patient const & v);
		int getpriority();
};

Patient :: Patient(){
	mobileno = new char[10];
	bgrp = new char[3];
	name = new char[20];
	disease = new char[20];
	pid = 0;
	prio = 1;
}

int Patient :: getpriority(){
	return prio;
}


void Patient :: scan(){
	cin.ignore();
	cout << "Enter Name of Person: ";
	cin.getline(name, 20);

	cout << "Enter Disease: ";
	cin.getline(disease, 20);

	prio = getprio(disease);

	cout << "Enter Patient ID: ";
	cin >> pid;
	
	cout << "Enter Mobile Number: ";
	cin.ignore();
	cin.getline(mobileno, 10);

	cout << "Enter Blood Group: ";
	cin.getline(bgrp, 3);
}

ostream & operator<<(ostream & Str, Patient const & v) {
	Str << "\n<---- Patient Detail ----->";
	Str << "\nName : " << v.name;
	Str << "\nDisease : " << v.disease;
	Str << "\nPriority : " << v.prio;
	Str << "\nPatient ID : " << v.pid;
	Str << "\nMobile Number : " << v.mobileno;
	Str << "\nBlood Group : " << v.bgrp;
	Str << "\n-----------------------------";
	return Str;
}

void menu(){
	cout << "\n1) Enter Patient Into Queue";
	cout << "\n2) Serve next Patient to the Doctor";
	cout << "\n3) Display List of all patient";
	cout << "\n4) Exit";
}

int getprio(char* dname){
	if(!(strcmp(dname,"accident") && strcmp(dname,"heart_attack")
			&& strcmp(dname,"panic_attack") && strcmp(dname,"fracture"))){
		return 3;
	}
	else if(!(strcmp(dname,"flu") && strcmp(dname,"cough") && strcmp(dname,"viral"))){
		return 2;
	} else {
		return 1;
	}
}

int main() {

	Patient p;
/*	Queue<Patient> patQ;
	int val = 0;

	while(val != 4){

		menu();
		cout << "\nEnter Choice: ";
		cin >> val;

		switch(val){
			case 1:
				p.scan();
				patQ.enque(p);
				cout << "\nPateint Added!";
				break;
			case 2:
				int maxp = 0;
				int i_at_max = 0;
				int s = patQ.size();

				for(int i=0; i<s; i++){
					p = patQ.getele(i);
					if(maxp < p.getpriority()){
						maxp = p.getpriority();
						i_at_max = i;
					}
				}
				patQ.deque(i_at_max);
				break;
			//case 3:
			//break;
		}
	} */

	Queue<int> test;

	int qn = 0, t;
	cout << "no. of ele:";
	cin >> qn;

	while(qn--){
		cout << "enter ele: ";
		cin >> t;
		test.enque(t);
	}

	test.printQ();

	return 0;
}

