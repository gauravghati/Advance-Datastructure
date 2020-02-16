/*
=========================================================================
Assignment : Implementation of Priority Queue
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Problem Statement:
	Consider a friends‘ network on face book social web site. Model it as a graph to
	represent each node as a user and a link to represent the fried relationship between
	them. Store data such as date of birth, number of comments for each user.
		1. Find who is having maximum friends
		2. Find who has post maximum and minimum comments
		3. Find users having birthday in this month
=========================================================================
*/

#include <iostream>
#include "SocialMedia.h"
using namespace std;

int main() {

	SocialMedia sm;

	sm.insertUser("Gaurav");
	sm.insertUser("Puneet");
	sm.insertUser("Ellika");
	sm.insertUser("Sakshee");

	sm.displayNetwork();

	return 0;
}
