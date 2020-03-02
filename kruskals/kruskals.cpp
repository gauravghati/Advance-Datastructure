/*
=========================================================================
Assignment : Implementation of Kruskal’s algorithms
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Problem Statement:
	Represent any real world graph using adjacency list /adjacency matrix find minimum
spanning tree using Kruskal‘s algorithm.
=========================================================================
*/

#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
	Graph g;

	g.createNetwork();

	g.insertVertex(1);
	g.insertVertex(2);
	g.insertVertex(3);
	g.insertVertex(4);

	g.addEdge(1, 2, 80);
	g.addEdge(2, 3, 90);
	g.addEdge(3, 4, 89);
	g.addEdge(1, 4, 78);

	return 0;
}
