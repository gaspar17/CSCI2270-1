#include <iostream>
#include "assignment4commNet.cpp"
using namespace std;

int main(){

  assignment4commNet a(10);
  City *head = new City(" ", nullptr, nullptr, " ");
  int userChoice;

  while(userChoice != 7){

    int userChoice;
    cin >> userChoice;

    cout << "======Main Menu======" << endl;
    cout << "1. Build Network" << endl;
    cout << "2. Print Network Path" << endl;
    cout << "3. Transmit Message Coast-To-Coast" << endl;
    cout << "4. Add City" << endl;
    cout << "5. Delete City" << endl;
    cout << "6. Clear Network" << endl;
    cout << "7. Quit" << endl;

    if(userChoice == 7){
      cout << "Goodbye!" << endl;
      return 0;
    }
    else if(userChoice == 1){
      a.buildNetwork();
    }
    else if(userChoice == 2){
      a.printNetwork();
    }
    else if(userChoice == 3){
      a.transmitMsg("messagein.txt");
    }
    else if(userChoice == 4){

    }
    else if(userChoice == 5){

    }
    else if(userChoice == 6){

    }
    else{
      cout << "Error, input not valid, please enter a number 1-7" << endl;
    }
  }

}
