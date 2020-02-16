/*
 * SocialMedia.h
 *
 *  Created on: Feb 6, 2020
 *      Author: f10
 */

#ifndef SOCIALMEDIA_H_
#define SOCIALMEDIA_H_

#include<string.h>
#include<iostream>
using namespace std;

class VertexNode;

class EdgeNode{					// FRIENDS
	public:
		EdgeNode();
		EdgeNode *nextEdge;
		VertexNode *nextVertex;
};

class VertexNode{				// USER
public:
	VertexNode();
	string name;
	int comments;
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
	void insertUser(string);
	void addFriend(string, string);
	void displayNetwork();
	virtual ~SocialMedia();
};

#endif /* SOCIALMEDIA_H_ */
