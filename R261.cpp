
//Recitation 2/6/18

#include <iostream>
using namespace std;

struct node{
  int value;
  node *next;
  node(int v, node *n){
    value = v;
    next = n;
  }
};

void createNode(int value, node * &head){ //pass address of head not value of head
  if(head == nullptr){
    node *temp = new node(value, nullptr);
    head = temp;
  }
  else{
    node *temp = head;
    while(temp -> next != nullptr){
      temp = temp -> next;
    }
    node *tail = new node(value, nullptr);
    temp -> next = tail;
  }
}

void insertNode(node * &temp){
  node *newNode = new node(-1, temp -> next);
  temp -> next = newNode;
}

int main(){

  node *head = nullptr;
  for(int i = 0; i < 5; i++){
    createNode(i, head);
  }

  node *temp = head;
  cout << "unedited list" << endl;
  while(temp != nullptr){
    cout << temp -> value << endl;
    temp = temp -> next;
  }

  temp = head;
  while(temp != nullptr){
    if(temp -> value % 2 == 0){
      insertNode(temp);
    }
    temp = temp -> next;  
  }

  temp = head;
  cout << "edited list" << endl;
  while(temp != nullptr){
    cout << temp -> value << endl;
    temp = temp -> next;
  }
}
