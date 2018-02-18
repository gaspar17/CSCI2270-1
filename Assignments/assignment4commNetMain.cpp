#include <iostream>
#include "CommunicationNetwork.cpp"
using namespace std;

int main(){

  CommunicationNetwork a;
  City *head = new City(" ", nullptr, nullptr, " ");
  int userChoice;

  while(userChoice != 7){

    int userChoice;

    cout << "======Main Menu======" << endl;
    cout << "1. Build Network" << endl;
    cout << "2. Print Network Path" << endl;
    cout << "3. Transmit Message Coast-To-Coast" << endl;
    cout << "4. Add City" << endl;
    cout << "5. Delete City" << endl;
    cout << "6. Clear Network" << endl;
    cout << "7. Quit" << endl;

    cin >> userChoice;

    if(userChoice == 7){ //Quit
      cout << "Goodbye!" << endl;
      return 0;
    }
    else if(userChoice == 1){ //Build Network (default)
      a.buildNetwork();
    }
    else if(userChoice == 2){ //Print path
      a.printNetwork();
    }
    else if(userChoice == 3){ //Transmit
      char *filename = (char*)"messageIn.txt";
      a.transmitMsg(filename);
    }
    else if(userChoice == 4){ //Add city
      string newCityName;
      string previousCityName;
      cout << "Enter a city name:" << endl;
      cin >> newCityName;
      cout << "Enter a previous city name:" << endl;
      cin >> previousCityName;
      a.addCity(newCityName, previousCityName);
    }
    else if(userChoice == 5){ //Delete city
      string removeCity;
      cout << "Enter a city name:" << endl;
      cin >> removeCity;
      a.deleteCity(removeCity);
    }
    else if(userChoice == 6){ //Clear network
      a.deleteNetwork();
    }
    else{
      cout << "Error, input not valid, please enter a number 1-7" << endl;
    }
  }

}
