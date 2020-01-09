/*
=========================================================================
Assignment : Implementation of Priority Queue
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Problem Statement:
Implement priority queue as ADT using single linked list for servicing
patients in an hospital with priorities as 
	i) Serious (top priority) 
	ii) medium illness (medium priority) 
	iii) General (Least priority)

=========================================================================
*/

#include <iostream>
#include "Queue.cpp"
#include "Queue.h"
#include <string.h>
using namespace std;

int getprio(string);

class Patient{
	string mobileno;			// mobile no
	int pid;					// patient id
	string bgrp;				// blood group
	int prio;					// priority
	string name;				// name and disease
	string disease;

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
	//cin.getline(name, 20);
	cin >> name;

	cout << "Enter Disease: ";
	//cin.getline(disease, 20);
	cin >> disease;

	prio = getprio(disease);

	cout << "Enter Patient ID: ";
	cin >> pid;
	
	cout << "Enter Mobile Number: ";
	cin.ignore();
	//cin.getline(mobileno, 10);
	cin >> mobileno;

	cout << "Enter Blood Group: ";
	//cin.getline(bgrp, 3);
	cin >> bgrp;
}

ostream & operator<<(ostream & Str, Patient const & v) {
	Str << "\n<---- Patient Detail ----->";
	Str << "\nName : " << v.name;
	Str << "\nDisease : " << v.disease;
	Str << "\nPriority : " << ((v.prio==3)? "(HIGH)":((v.prio==2)? "(MEDIUM)":"(LOW)"));
	Str << "\nPatient ID : " << v.pid;
	Str << "\nMobile Number : " << v.mobileno;
	Str << "\nBlood Group : " << v.bgrp;
	Str << "\n---------------------------";
	return Str;
}

void menu(){
	cout << "\n1) Enter Patient Into Queue";
	cout << "\n2) Serve next Patient to the Doctor";
	cout << "\n3) Display List of all patient";
	cout << "\n4) Exit";
}

int getprio(string dname){
	if(!(dname.compare("accident") && dname.compare("heart_attack")
			&& dname.compare("panic_attack") && dname.compare("fracture"))){
		return 3;
	}
	else if(!(dname.compare("flu") && dname.compare("cough") && dname.compare("viral"))){
		return 2;
	} else {
		return 1;
	}
}

int main() {
	Patient p;
	Queue<Patient> patQ;
	int val = 0;
	int maxp = 0;
	int i_at_max = 0;
	int s = 0;

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
				maxp = 0;
				i_at_max = 0;
				s = patQ.size();
				cout << "\nNEXT PATIENT";
				for(int i=0; i<s; i++){
					p = patQ.getele(i+1);
					if(maxp < p.getpriority()){
						maxp = p.getpriority();
						cout << maxp;
						i_at_max = i+1;
					}
				}
				cout << patQ.deque(i_at_max);
				break;
			case 3:
				cout << "=======================================";
				cout << "\nLIST OF ALL PATIENTS IN QUEUE: ";
				patQ.printQ();
				cout << endl;
				cout << "=======================================";
				break;
		}
	} 

	return 0;
}

/*

OUTPUT:

1) Enter Patient Into Queue
2) Serve next Patient to the Doctor
3) Display List of all patient
4) Exit
Enter Choice: 1

Enter Name of Person: gaurav
Enter Disease: flu
Enter Patient ID: 101
Enter Mobile Number: 902341487 
Enter Blood Group: o+

Pateint Added!

1) Enter Patient Into Queue
2) Serve next Patient to the Doctor
3) Display List of all patient
4) Exit
Enter Choice: 1

Enter Name of Person: sahil
Enter Disease: accident 
Enter Patient ID: 102 
Enter Mobile Number: 9128379142
Enter Blood Group: ab+

Pateint Added!

1) Enter Patient Into Queue
2) Serve next Patient to the Doctor
3) Display List of all patient
4) Exit
Enter Choice: 1

Enter Name of Person: raje
Enter Disease: head_pain
Enter Patient ID: 104  
Enter Mobile Number: 293746823
Enter Blood Group: a-

Pateint Added!

1) Enter Patient Into Queue
2) Serve next Patient to the Doctor
3) Display List of all patient
4) Exit
Enter Choice: 1

Enter Name of Person: shreyas
Enter Disease: heart_attack
Enter Patient ID: 2001
Enter Mobile Number: 29384928 
Enter Blood Group: b- 

Pateint Added!

1) Enter Patient Into Queue
2) Serve next Patient to the Doctor
3) Display List of all patient
4) Exit
Enter Choice: 3

=======================================
LIST OF ALL PATIENTS IN QUEUE: 
<---- Patient Detail ----->
Name : gaurav
Disease : flu
Priority : (MEDIUM)
Patient ID : 101
Mobile Number : 902341487
Blood Group : o+
---------------------------
<---- Patient Detail ----->
Name : sahil
Disease : accident
Priority : (HIGH)
Patient ID : 102
Mobile Number : 9128379142
Blood Group : ab+
---------------------------
<---- Patient Detail ----->
Name : raje
Disease : head_pain
Priority : (LOW)
Patient ID : 104
Mobile Number : 293746823
Blood Group : a-
---------------------------
<---- Patient Detail ----->
Name : shreyas
Disease : heart_attack
Priority : (HIGH)
Patient ID : 2001
Mobile Number : 29384928
Blood Group : b-
---------------------------
=======================================

1) Enter Patient Into Queue
2) Serve next Patient to the Doctor
3) Display List of all patient
4) Exit
Enter Choice: 2

NEXT PATIENT
<---- Patient Detail ----->
Name : sahil
Disease : accident
Priority : (HIGH)
Patient ID : 102
Mobile Number : 9128379142
Blood Group : ab+
---------------------------

1) Enter Patient Into Queue
2) Serve next Patient to the Doctor
3) Display List of all patient
4) Exit
Enter Choice: 2

NEXT PATIENT
<---- Patient Detail ----->
Name : shreyas
Disease : heart_attack
Priority : (HIGH)
Patient ID : 2001
Mobile Number : 29384928
Blood Group : b-
---------------------------

1) Enter Patient Into Queue
2) Serve next Patient to the Doctor
3) Display List of all patient
4) Exit
Enter Choice: 2

NEXT PATIENT
<---- Patient Detail ----->
Name : gaurav
Disease : flu
Priority : (MEDIUM)
Patient ID : 101
Mobile Number : 902341487
Blood Group : o+
---------------------------

1) Enter Patient Into Queue
2) Serve next Patient to the Doctor
3) Display List of all patient
4) Exit
Enter Choice: 2

NEXT PATIENT
<---- Patient Detail ----->
Name : raje
Disease : head_pain
Priority : (LOW)
Patient ID : 104
Mobile Number : 293746823
Blood Group : a-
---------------------------

1) Enter Patient Into Queue
2) Serve next Patient to the Doctor
3) Display List of all patient
4) Exit
Enter Choice: 4

*/