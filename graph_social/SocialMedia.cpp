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
	EdgeNode *newfriend = new EdgeNode;
	
}	


void SocialMedia::displayNetwork(){
	VertexNode *vptr = G->head;

	while(vptr != NULL){
		cout << (vptr->name) << "\n";
		vptr = vptr -> nextVertex;
	}
}
