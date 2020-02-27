/*
 * Graph.h
 *
 *  Created on: Feb 27, 2020
 *      Author: f10
 */

#ifndef GRAPH_H_
#define GRAPH_H_

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
	int value;
public:
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
public:
	Graph();
	void createNetwork();
	void addEdge(int, int);
	void insertVertex(int);
	void displayNetwork();
	virtual ~Graph();
};

#endif /* GRAPH_H_ */
