/*
 * Graph.cpp
 *
 *  Created on: Feb 27, 2020
 *      Author: f10
 */

#include "Graph.h"

#include <iostream>

VertexNode::VertexNode() {
	visited = false;
	nextVertex = NULL;
	nextEdge = NULL;
}

EdgeNode::EdgeNode() {
	intree = false;
	weight = 0;
	nextVertex = NULL;
	nextEdge = NULL;
}

Graph::Graph() {
	G = NULL;
}

Graph::~Graph() {

}

void Graph::createNetwork(){
	G=new GraphHead;
	G->count=0;
	G->head = new VertexNode;
}

void Graph::insertVertex(int val){
	VertexNode *newPtr = new VertexNode;

	VertexNode *temp;
	temp = G->head;
	int n = G->count;

	if(n==0){
		G->head = newPtr;
		G->count += 1;
	}

	while(temp->nextVertex!=NULL){
		temp = temp->nextVertex;
	}
	temp->nextVertex = newPtr;
	G->count += 1;
}

