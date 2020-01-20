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
#include "BTree.cpp"

using namespace std;

int main() {
	BTree<int> p;

	p.insert(34);
	p.insert(45);
	p.insert(55);
	p.insert(66);
	p.insert(89);
	p.insert(23);
	p.insert(67);

	p.disleafs();
	return 0;
}
