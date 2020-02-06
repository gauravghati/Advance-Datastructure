/*
 * LinkedList.h
 *
 *  Created on: Feb 6, 2020
 *      Author: f10
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include<string.h>
#include<iostream>
using namespace std;

class VertexNode;

class EdgeNode{					// FRIENDS
	public:
		EdgeNode *nextEdge;
		VertexNode *nextVertex;
};

class VertexNode{				// USER
public:
		string name;
		int n_comments;
		int dd, mm, yyyy;
		bool visted;
		EdgeNode *nextEdge;
		VertexNode *nextVertex;
};

class GraphHead{
public:
	int count;
	VertexNode *head;
};

class SocialMedia {
	GraphHead *G;
public:
	SocialMedia();
	void createNetwork();
	VertexNode* getUser(string);
	void insertUser();
	void addFriend();
	void displayNetwork();
	virtual ~SocialMedia();
};

#endif /* LINKEDLIST_H_ */


/*


class graphSocialnetwork {

	graphHead *G;
	//graphEdge E;

public:
	graphSocialnetwork();
	virtual ~graphSocialnetwork();
	void createGraph();
	graphVertex* getVertex(string);
	int insertVertex(string );
	int insertEdge(string, string,int);
	void displayGraph();
	//other program related functions

};

graphSocialnetworkl::graphKruskal() {
	// TODO Auto-generated constructor stub
	G=NULL;
}

graphSocialnetwork::~graphKruskal() {
	// TODO Auto-generated destructor stub
}

void graphSocialnetwork::createGraph()
{
	G=new graphHead;
	G->count=0;
	G->firstVertex=NULL;
}

graphVertex* graphKruskal:: getVertex(string name)
{
	graphVertex *newptr;
	//allocate the memory for newptr

	G->count=G->count+1;

	return newptr;
}

//graphEdge* graphKruskal::getEdge()


int graphSocialnetwork::insertVertex(string name)
{
	graphVertex *newPtr,*locPtr;
	newPtr=getVertex(name);
	//Insert the new user/vertex in the network/graph. Here we have just taken name (string). U can get complete details (struct object).
	return 1;
}

int graphSocialnetwork::insertEdge(string startVertex, string endVertex, int w)
{
	graphVertex *fromPtr, *toPtr;
	//Insert Edge (friend of user and create the proper links)

	return 1;
}

void graphSocialnetwork::displayGraph()
{
	graphVertex *vertexPtr;
	graphEdge *edgePtr;
	//display the graph in adjacency list form
}


main() method

create graph
Insert vertices
Insert Edges
display Graph
Perform Operations


*/


