/*
 * SocialMedia.cpp
 *
 *  Created on: Feb 6, 2020
 *      Author: f10
 */

#include "SocialMedia.h"
#include <iostream>
#include <list>

VertexNode::VertexNode() {
	nextVertex = NULL;
	nextEdge = NULL;
	visited = false;
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
	cout << "comments: ";
	cin >> (newPtr-> comments);
	 cout << "\nEnter date of birth: \n";
	 do{
		 cout << "dd: ";
		 cin >> (newPtr-> dd);
	 }while(newPtr->dd<0 || newPtr->dd > 31);

	 do{
		 cout << "mm: ";
		 cin >> (newPtr-> mm);
	 }while(newPtr->mm<0 || newPtr->mm > 12);

	 do{
		 cout << "yyyy: ";
		 cin >> (newPtr-> yyyy);
	 }while(newPtr->yyyy<1990 || newPtr->yyyy > 2020);

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

	// setting both user in VertexNode variable
	while(temp != NULL){
		if(temp->name == toname){
			tovertex = temp;
			one = true;
		} if(temp->name == fromname){
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


void SocialMedia::displayNetwork(){
	VertexNode *vptr = G->head;
	cout << "Users :: \tFriends\n";
	while(vptr != NULL){
		cout << (vptr->name) << "    :: ";
		EdgeNode *friends = vptr->nextEdge;

		while(friends != NULL){
			cout << (friends->nextVertex->name) << ((friends->nextEdge==NULL)? "" : " , ");
			friends = friends->nextEdge;
		}
		cout << "\n";
		vptr = vptr -> nextVertex;
	}
}

void SocialMedia::maxFriend(){
	VertexNode *vptr = G->head;
	VertexNode *maxv;

	int max = 0;

	while(vptr != NULL){
		int count = 0;
		EdgeNode *friends = vptr->nextEdge;

		while(friends != NULL){
			count++;
			friends = friends->nextEdge;
		}
		if(count>max){
			max = count;
			maxv = vptr;
		}
		vptr = vptr -> nextVertex;
	}

	cout << maxv->name << " have maximum number of friends i.e. " << max << "\n";
}

void SocialMedia::bfs_max_min(){
	list<VertexNode*> queue;
	VertexNode *temp = G->head, *val=temp;

	int max = temp->comments, min = temp->comments;
	VertexNode *maxv, *minv;

	while(val != NULL){
		val->visited = false;
		val = val->nextVertex;
	}

	temp->visited = true;
	queue.push_back(temp);

    while(!queue.empty()) {
        temp = queue.front();
        queue.pop_front();

        EdgeNode *frd = temp->nextEdge;
       	while(frd != NULL){
       		if(!frd->nextVertex->visited){
       			frd->nextVertex->visited = true;
       			queue.push_back(frd->nextVertex);
       		}
       		if(frd->nextVertex->comments > max){
       			maxv = frd->nextVertex;
       			max = maxv->comments;
       		}

       		if(frd->nextVertex->comments < min){
       			minv = frd->nextVertex;
       			min = minv->comments;
       		}
       		frd = frd -> nextEdge;
       	}
    }
    cout << "\n";
    cout << "Maximum Comments: "<< max << "\nMinimum Comments: " << min << "\n";
}

void SocialMedia::dfs_month(int mm){
	list<VertexNode*> stack;
	VertexNode *temp = G->head;

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
       		}
       		if(frd->nextVertex->mm == mm){
       			user = frd->nextVertex;
       		}
       		frd = frd -> nextEdge;
       	}
    }
    if(user == NULL){
    	cout << "User Not Found.\n";
    } else {
        cout << "\nUser having birthday in that month is: " << user->name << "\n";
    }
}
