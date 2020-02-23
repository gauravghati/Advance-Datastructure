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
#include "SocialMedia.cpp"
using namespace std;

int main() {

	SocialMedia sm;

	sm.createNetwork();
	sm.insertUser("a");
	sm.insertUser("b");
	sm.insertUser("c");
	sm.insertUser("d");
	sm.addFriend("a", "b");
	sm.addFriend("b", "c");
	sm.addFriend("a", "c");
	sm.addFriend("d", "a");

	sm.displayNetwork();

	sm.maxFriend("a");

	sm.bfs();

	return 0;
}
