/*
 * SocialMedia.cpp
 *
 *  Created on: Feb 6, 2020
 *      Author: f10
 */

#include "SocialMedia.h"
#include <iostream>

VertexNode::VertexNode() {
	nextVertex = NULL;
	nextEdge = NULL;
}

EdgeNode::EdgeNode() {
	nextVertex = NULL;
	nextEdge = NULL;
}

SocialMedia::SocialMedia() {
	G=NULL;
}

SocialMedia::~SocialMedia() {

}

void SocialMedia::createNetwork(){
	G=new GraphHead;
	G->count=0;
	G->head = new VertexNode;
}

VertexNode* SocialMedia::getUser(string name){

}

void SocialMedia::insertUser(string name){
	VertexNode *newPtr = new VertexNode;

	newPtr->name = name;
	cout << "\nEnter no. of comments: ";
	cin >> (newPtr-> comments);
	cout << "\nEnter date of birth\ndd: ";
	cin >> (newPtr-> dd);
	cout << "\nmm: ";
	cin >> (newPtr-> mm);
	cout << "\nyyyy: ";
	cin >> (newPtr-> yyyy);

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

void SocialMedia::addFriend(string toname, string fromname) {
	EdgeNode *toedge = new EdgeNode;
	EdgeNode *fromedge = new EdgeNode;

	VertexNode *tovertex, *fromvertex;
	bool one=false, two=false;
	VertexNode *temp = G->head;
	while(temp->nextVertex != NULL){
		if(temp->name == toname){
			tovertex = temp;
			one = true;
		} if(temp->name == fromname){
			fromvertex = temp;
			two = true;
		}
		temp = temp->nextVertex;
	}
	if(one && two){
		toedge->nextVertex = tovertex;
		fromedge->nextVertex = fromvertex;

		EdgeNode *tempe = tovertex->nextEdge;
		while(tempe!=NULL && tempe->nextEdge!=NULL){
			tempe = tempe->nextEdge;
		} if(tempe==NULL){
			tempe = fromedge;
		} else {
			tempe->nextEdge = fromedge;
		}

		tempe = fromvertex->nextEdge;
		while(tempe!=NULL && tempe->nextEdge!=NULL){
			tempe = tempe->nextEdge;
		} if(tempe==NULL){
			tempe = toedge;
		} else {
			tempe->nextEdge = toedge;
		}
	}
}


void SocialMedia::displayNetwork(){
	VertexNode *vptr = G->head;

	while(vptr != NULL){
		cout << (vptr->name) << " -> ";
		EdgeNode *friends = vptr->nextEdge;

		while(friends != NULL){
			cout << (friends->nextVertex->name) << "->";
			friends = friends->nextEdge;
		}
		cout << "\n";
		vptr = vptr -> nextVertex;
	}
}
