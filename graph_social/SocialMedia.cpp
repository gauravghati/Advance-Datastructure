/*
 * SocialMedia.cpp
 *
 *  Created on: Feb 6, 2020
 *      Author: f10
 */

#include "SocialMedia.h"
#include <iostream>

SocialMedia::SocialMedia() {
	G=NULL;
}

SocialMedia::~SocialMedia() {

}

void SocialMedia::createNetwork(){
	G=new GraphHead;
	G->count=0;
	G->head = NULL;
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

	VertexNode * temp;
	temp = G->head;
	int n = G->count;

	if(n==0){
		G->head = newPtr;
		(G->count)++;
	}

	while(n!=0){
		temp = temp->nextVertex;
		n--;
	}
	temp->nextVertex = newPtr;
}

void SocialMedia::addFriend() {

}	


void SocialMedia::displayNetwork(){
	VertexNode *vptr = G->head;
	int n = G->count;

	while(n--){
		cout << (vptr->name);
		vptr = vptr -> nextVertex;
	}
}