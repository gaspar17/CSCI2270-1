#include "sll.h"
#include <iostream>
using namespace std;

SLL::SLL(){
  //default constructor
}
//SLL constructor that takes an int
SLL::SLL(int nodeID){
  //creates the head node
  head = new Node;
  head -> next = nullptr;
  head -> id = nodeID;

}
SLL::~SLL(){
  //free the memory for the linked list
  if(head != nullptr){
    cout << "deleting " << head -> id << endl;
    delete head;
  }
}

bool SLL::insertNodeAtEnd(int nodeID){
  //check if head is null and if so create a head node, if
  //head is not null, add a new node at end of list
  Node *newNode = new Node;
  newNode -> next = nullptr;
  newNode -> id = nodeID;

  //tail pointer could be used and set new node a tail -> next
  //then tail = newNode
  if(head == nullptr){
    head = newNode;
  }
  else{
    Node *current = head;
    while(current -> next != nullptr){
      current = current -> next;
    }
    current -> next = newNode;
  }

  return true;
}

void SLL::printList(){
  Node *tmp = head; //wont work if list is empty, wont enter while loop
  //can call head despite it being private since printList is a member of the class which head is contained in'''

  while(tmp != nullptr){
    cout << tmp -> id << endl;
    tmp = tmp -> next;
  }
}
