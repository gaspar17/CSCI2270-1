#include <iostream>
#include "doublyLL.h"
using namespace std;

doublyLL::doublyLL() {

}

doublyLL::doublyLL(int nodeID) {
	//create head node
	head = createNode(nodeID, nullptr, nullptr);
	tail = head;
}

doublyLL::~doublyLL() {

}


Node* doublyLL::createNode(int nodeID, Node* nodePrev, Node* nodeNext) {
	Node* newNode = new Node;
	newNode->id = nodeID;
	newNode->next = nodeNext;
	newNode->prev = nodePrev;

	return newNode;
}

bool doublyLL::insertNodeAtEnd(int nodeID) {
	if (head == nullptr) {
		//nothing in the list
		head = createNode(nodeID, nullptr, nullptr);
		tail = head;
	}
	else {
		Node* newNode = createNode(nodeID, tail, nullptr);
		tail->next = newNode;
		tail = newNode;
	}
	return true;
}

void doublyLL::printList(){
	Node *temp = head;
	while(temp != nullptr){
		cout << temp -> id << endl;
		temp = temp -> next;
	}
}

void doublyLL::removeNode(Node *node){
	Node *temp = head;
	while(temp != node){
		temp = temp -> next;
	}
	temp -> prev -> next = temp -> next;
	temp -> next -> prev = temp -> prev;
	delete[] temp;
}

void doublyLL::findDuplicates(){
	Node *temp = head;
	Node *temp2 = head -> next;
	while(temp != tail){
		while(temp2 != nullptr){
			if(temp -> id == temp2 -> id){
				removeNode(temp2);
				temp2 = temp;
			}
			temp2 = temp2 -> next;
		}
		temp = temp -> next;
	}
}
