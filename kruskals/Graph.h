/*
 * Graph.h
 *
 *  Created on: Feb 27, 2020
 *      Author: f10
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include<iostream>
using namespace std;

class VertexNode;

class EdgeNode{					// Edge
	public:
		int weight;
		bool intree;
		EdgeNode();
		EdgeNode *nextEdge;
		VertexNode *nextVertex;
};

class VertexNode{				// VERTEX
public:
	int value;
	VertexNode();
	bool visited;
	EdgeNode *nextEdge;
	VertexNode *nextVertex;
};

class GraphHead{
public:
	int count;
	VertexNode *head;
};

class Graph {
	GraphHead *G;
	void displayTree();
	EdgeNode* dir_min();
	bool allvisited();
public:
	Graph();
	void createNetwork();
	void addEdge(int, int, int);
	void insertVertex(int);
	void displayNetwork();
	void minimumSpanningTree();
	virtual ~Graph();
};

#endif /* GRAPH_H_ */
