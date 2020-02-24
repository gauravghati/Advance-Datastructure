/*
=========================================================================
Assignment : Implementation of Priority Queue
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Problem Statement:
	Consider a friends‘ network on face book social web site. Model it as a graph to
	represent each node as a user and a link to represent the friend relationship between
	them. Store data such as date of birth, number of comments for each user.
		1. Find who is having maximum friends
		2. Find who has post maximum and minimum comments
		3. Find users having birthday in this month
=========================================================================
*/

#include <iostream>
#include "SocialMedia.h"
using namespace std;

void menu(){
	cout << "1) Insert User in Social Media\n";
	cout << "2) Connect two users as Friend\n";
	cout << "3) Display Network\n";
	cout << "4) Find who is having maximum friends\n";
	cout << "5) Find who has post maximum and minimum comments\n";
	cout << "6) Find users having birthday in this month\n";
	cout << "7) Exit\n";
	cout << "Enter Choice:";
}

int main() {

	int ch, mm;
	bool exit = false;
	string name, frdname;
	SocialMedia sm;

	sm.createNetwork();

	while(!exit){
		menu();
		cin >> ch;

		switch(ch){
			case 1:
				cout << "\n---------Insert User Data-----------";
				cout << "\nEnter Name of User: ";
				cin >> name;
				sm.insertUser(name);
				cout << "User Added Successfully \n\n";
				break;

			case 2:
				cout << "\nEnter Name of 1st User: ";
				cin >> name;
				cout << "\nEnter Name of 2nd User: ";
				cin >> frdname;
				sm.addFriend(name, frdname);
				cout << "Connection Added Successfully\n\n";
				break;

			case 3:
				cout << "----- Social Network -------\n";
				sm.displayNetwork();
				cout << "\n";
				break;

			case 4:
				sm.maxFriend();
				cout << "\n";
				break;

			case 5:
				sm.bfs_max_min();
				cout << "\n";
				break;

			case 6:
				cout << "\nEnter the Month: ";
				cin >> mm;
				sm.dfs_month(mm);
				cout << "\n";
				break;

			case 7:
				exit = true;
		}
	}
	return 0;
}

/*

OUTPUT:


1) Insert User in Social Media
2) Connect two users as Friend
3) Display Network
4) Find who is having maximum friends
5) Find who has post maximum and minimum comments
6) Find users having birthday in this month
7) Exit
Enter Choice:1

---------Insert User Data-----------
Enter Name of User: Gaurav
comments: 23

Enter date of birth:
dd: 25
mm: 05
yyyy: 2000
User Added Successfully

1) Insert User in Social Media
2) Connect two users as Friend
3) Display Network
4) Find who is having maximum friends
5) Find who has post maximum and minimum comments
6) Find users having birthday in this month
7) Exit
Enter Choice:1

---------Insert User Data-----------
Enter Name of User: Puneet
comments: 45

Enter date of birth:
dd: 20
mm: 06
yyyy: 1999
User Added Successfully

1) Insert User in Social Media
2) Connect two users as Friend
3) Display Network
4) Find who is having maximum friends
5) Find who has post maximum and minimum comments
6) Find users having birthday in this month
7) Exit
Enter Choice:1

---------Insert User Data-----------
Enter Name of User: Ellika
comments: 09

Enter date of birth:
dd: 09
mm: 08
yyyy: 2000
User Added Successfully

1) Insert User in Social Media
2) Connect two users as Friend
3) Display Network
4) Find who is having maximum friends
5) Find who has post maximum and minimum comments
6) Find users having birthday in this month
7) Exit
Enter Choice:1

---------Insert User Data-----------
Enter Name of User: Shivam
comments: 56

Enter date of birth:
dd: 31
mm: 06
yyyy: 1998
User Added Successfully

1) Insert User in Social Media
2) Connect two users as Friend
3) Display Network
4) Find who is having maximum friends
5) Find who has post maximum and minimum comments
6) Find users having birthday in this month
7) Exit
Enter Choice:2

Enter Name of 1st User: Gaurav

Enter Name of 2nd User: Puneet
Connection Added Successfully

1) Insert User in Social Media
2) Connect two users as Friend
3) Display Network
4) Find who is having maximum friends
5) Find who has post maximum and minimum comments
6) Find users having birthday in this month
7) Exit
Enter Choice:2

Enter Name of 1st User: Gaurav

Enter Name of 2nd User: Ellika
Connection Added Successfully

1) Insert User in Social Media
2) Connect two users as Friend
3) Display Network
4) Find who is having maximum friends
5) Find who has post maximum and minimum comments
6) Find users having birthday in this month
7) Exit
Enter Choice:2

Enter Name of 1st User: Puneet

Enter Name of 2nd User: Ellika
Connection Added Successfully

1) Insert User in Social Media
2) Connect two users as Friend
3) Display Network
4) Find who is having maximum friends
5) Find who has post maximum and minimum comments
6) Find users having birthday in this month
7) Exit
Enter Choice:2

Enter Name of 1st User: Shivam

Enter Name of 2nd User: Gaurav
Connection Added Successfully

1) Insert User in Social Media
2) Connect two users as Friend
3) Display Network
4) Find who is having maximum friends
5) Find who has post maximum and minimum comments
6) Find users having birthday in this month
7) Exit
Enter Choice:3
----- Social Network -------
Users :: 	Friends
Gaurav    :: Puneet , Ellika , Shivam
Puneet    :: Gaurav , Ellika
Ellika    :: Gaurav , Puneet
Shivam    :: Gaurav

1) Insert User in Social Media
2) Connect two users as Friend
3) Display Network
4) Find who is having maximum friends
5) Find who has post maximum and minimum comments
6) Find users having birthday in this month
7) Exit
Enter Choice:4
Gaurav have maximum number of friends i.e. 3

1) Insert User in Social Media
2) Connect two users as Friend
3) Display Network
4) Find who is having maximum friends
5) Find who has post maximum and minimum comments
6) Find users having birthday in this month
7) Exit
Enter Choice:5

Maximum Comments: 56
Minimum Comments: 9

1) Insert User in Social Media
2) Connect two users as Friend
3) Display Network
4) Find who is having maximum friends
5) Find who has post maximum and minimum comments
6) Find users having birthday in this month
7) Exit
Enter Choice:6

Enter the Month: 08
User having birthday in that month is: Ellika

1) Insert User in Social Media
2) Connect two users as Friend
3) Display Network
4) Find who is having maximum friends
5) Find who has post maximum and minimum comments
6) Find users having birthday in this month
7) Exit
Enter Choice:6

Enter the Month: 05
User having birthday in that month is: Gaurav

1) Insert User in Social Media
2) Connect two users as Friend
3) Display Network
4) Find who is having maximum friends
5) Find who has post maximum and minimum comments
6) Find users having birthday in this month
7) Exit
Enter Choice:7

*/
