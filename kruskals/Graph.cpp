/*
 * Graph.cpp
 *
 *  Created on: Feb 27, 2020
 *      Author: f10
 */

#include "Graph.h"
#include <iostream>
#include <list>


VertexNode::VertexNode() {
	value = 0;
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
	newPtr->value = val;

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

EdgeNode* Graph :: bfs_min(){				// Find Min Edge
	list<VertexNode*> stack;
	VertexNode *temp = G->head;

	EdgeNode* min = new EdgeNode;
	min = temp->nextEdge;

	VertexNode *user = NULL, *val=temp;
	while(val != NULL){
		val->visited = false;
		val = val->nextVertex;
	}

	temp->visited = true;
	stack.push_back(temp);

    while(!stack.empty()) {
        temp = stack.back();
        stack.pop_back();

        EdgeNode *frd = temp->nextEdge;
       	while(frd != NULL){
       		if(!frd->nextVertex->visited){
   				frd->nextVertex->visited = true;
   				stack.push_back(frd->nextVertex);

       			if(min->weight > frd->weight){
       				min = frd;
       			}
       		}
       		frd = frd -> nextEdge;
       	}
    }
    return min;
}

void Graph::addEdge(int toval, int fromval, int weight) {
	EdgeNode *toedge = new EdgeNode;
	EdgeNode *fromedge = new EdgeNode;

	toedge->weight = weight;
	fromedge->weight = weight;

	VertexNode *tovertex, *fromvertex;
	bool one=false, two=false;
	VertexNode *temp = G->head;

	// setting both user in VertexNode variable
	while(temp != NULL){
		if(temp->value == toval){
			tovertex = temp;
			one = true;
		} if(temp->value == fromval){
			fromvertex = temp;
			two = true;
		}
		temp = temp->nextVertex;
	}

	// if both variable is true
	if(one && two){
		// connecting to next node
		toedge->nextVertex = tovertex;
		fromedge->nextVertex = fromvertex;

		// adding 1st vertex as friend of 2nd
		EdgeNode *tempe = tovertex->nextEdge;
		while(tempe!=NULL && tempe->nextEdge!=NULL){
			tempe = tempe->nextEdge;
		}
		if(tempe==NULL){
			tovertex->nextEdge = fromedge;
		} else {
			tempe->nextEdge = fromedge;
		}

		// adding 2nd vertex as friend of 1st
		tempe = fromvertex->nextEdge;
		while(tempe!=NULL && tempe->nextEdge!=NULL){
			tempe = tempe->nextEdge;
		}
		if(tempe==NULL){
			fromvertex->nextEdge = toedge;
		} else {
			tempe->nextEdge = toedge;
		}
	}
}

void Graph::displayNetwork(){
	VertexNode *vptr = G->head;
	std :: cout << "Vertex ::  Edges\n";
	while(vptr != NULL){
		std :: cout << (vptr->value) << "      :: ";
		EdgeNode *friends = vptr->nextEdge;

		while(friends != NULL){
			std :: cout << (friends->nextVertex->value) << ((friends->nextEdge==NULL)? "" : " , ");
			friends = friends->nextEdge;
		}
		std :: cout << "\n";
		vptr = vptr -> nextVertex;
	}
}

void Graph::displayTree(){
	VertexNode *vptr = G->head;
		std :: cout << "Vertex ::  Edges\n";
		while(vptr != NULL){
			std :: cout << (vptr->value) << "      :: ";
			EdgeNode *friends = vptr->nextEdge;

			while(friends != NULL){
				if(friends->intree){
					std :: cout << (friends->nextVertex->value) << ((friends->nextEdge==NULL)? "" : " , ");
				}
				friends = friends->nextEdge;
			}
			std :: cout << "\n";
			vptr = vptr -> nextVertex;
		}
}

bool Graph :: allvisited(){
	VertexNode *vptr = G->head;
	while(vptr != NULL){
		vptr = vptr->nextVertex;
		if(!vptr->visited)
			return false;
	}
	return true;
}

void Graph :: minimumSpanningTree(){
	EdgeNode *min;
	while(!allvisited()){
		min = bfs_min();
		min->intree = true;
	}
	displayTree();
}
