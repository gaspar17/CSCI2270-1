//Lecture code 1/29 & 1/31

#include <iostream>
using namespace std;

struct node{
  int key;
  node *next;
  node(int k, node *n){
    key = k;
    next = n;
  }
};

node *search(int value, node *head){

  node *current = head;
  while(current != NULL){
    if(current -> key == value){
      return current;
    }
    current = current -> next;
  }

  return NULL;

}

int main(){
  node *x = new node(5, NULL);
  //print x.key
  cout << x-> key << endl;

  node *x2 = new node(6, NULL);
  cout << x2 -> key << endl;
  cout << x2 << endl;
  cout << x -> next << endl;

  x -> next = x2;

  node *x3 = new node(7, NULL);
  cout << x3 -> key << endl;

  x2 -> next = x3;

  int i = 1;
  node *head = new node(i, NULL);
  node *p = head; //head and p point to the same memory
  i++;

  while(i <= 10){
    node *n = new node(i, NULL); //set n -> next = NULL
    p -> next = n; //set p's next node to point to n
    p = n; //same as p = p -> next;
    i++;
  }
  //go back to beginning of list
  p = head;
  while(p != NULL){
    cout << p -> key << endl;
    p = p -> next;
  }

  //Finding something in the list
  //Is there a key value equal to 4

  p = head;
  while(p != NULL){
    if(p -> key == 4){
      cout << p -> key << endl;
    }
    p = p -> next;
  }

  p = search(17, head); //returns pointer to searched value if found
  if(p != NULL){
    cout << p << endl;
  }
  else{
    cout << "not in list" << endl;
  }

  

}
