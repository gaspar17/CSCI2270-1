//Recitation 2/13

#include <iostream>
#include "doublyLL.cpp"
using namespace std;

int main(){
  doublyLL a(7);
  int i [24] = {5, 6, 8, 1, 1, 78, 16, 1, 89, 24, 2, 34, 33, 61, 1, 19, 71, 42, 65, 22, 21, 0, 1, 9,};
  for(int j = 0; j < 24; j++){
    a.insertNodeAtEnd(i[j]);
  }
  a.printList();
  cout << "Removing Duplicates" << endl;
  a.findDuplicates();
  a.printList();
}
