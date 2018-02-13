#include <iostream>
#include "sll.h"

int main(){
  SLL llCoolList(10);
  //these methods are public which is why we can call them from this file
  //trying to reference head and tail wont work since they are private members of the class
  llCoolList.insertNodeAtEnd(12);
  llCoolList.insertNodeAtEnd(13);
  llCoolList.insertNodeAtEnd(14);
  llCoolList.insertNodeAtEnd(16);
  llCoolList.insertNodeAtEnd(17);
  llCoolList.insertNodeAtEnd(18);
  llCoolList.insertNodeAtEnd(19);
  llCoolList.insertNodeAtEnd(20);
  llCoolList.printList();
}
