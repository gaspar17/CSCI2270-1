//Assignment 3
//Due 2/11
//Evan Spruston

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct city{
  string cityName;
  city *next;
  string message;

  city(string c, city *n, string m){
    cityName = c;
    next = n;
    message = m;
  }
};

int promptUser(){

  int userChoice;

  cout << "======Main Menu======" << endl;
  cout << "1. Build Network" << endl;
  cout << "2. Print Network Path" << endl;
  cout << "3. Transmit Message Coast-To-Coast" << endl;
  cout << "4. Add City" << endl;
  cout << "5. Quit" << endl;
  cin >> userChoice;

  return userChoice;
}

void destroyList(city * &head){

  city *temp = head;
  while(temp -> next != nullptr){
    head = temp -> next;
    delete[] temp;
  }
  delete[] temp;
}

void printPath(city *head){
  city *temp = head;
  cout << "===CURRENT PATH===" << endl;
  while(temp -> next != nullptr){
    cout << temp -> cityName << " -> ";
    temp = temp -> next;
  }
  cout << temp -> cityName << " -> " << " NULL" << endl << "==================" << endl;
}

city buildNetwork(){

  //destroyList(head);

  city *head = new city(" ", nullptr, " ");
  city *Bos = new city("Boston", nullptr, " ");
  city *NY = new city("New York", Bos, " ");
  city *WashDC = new city("Washington, D.C.", NY, " ");
  city *Atl = new city("Atlanta", WashDC, " ");
  city *Chi = new city("Chicago", Atl, " ");
  city *StL = new city("St. Louis", Chi, " ");
  city *Dal = new city("Dallas", StL, " ");
  city *Den = new city("Denver", Dal, " ");
  city *Pho = new city("Phoenix", Den, " ");
  city *LA = new city("Los Angeles", Pho, " ");
  head = LA;

  return *head;
}

void transmitMsg(city * &head){
  if(head == nullptr){
    cout << "Empty list" << endl;
  }
  city *temp = head;

  ifstream messageStream;
  string line;
  string word;
  messageStream.open("messageIn.txt");

  if(messageStream.is_open()){
    getline(messageStream, line);
    stringstream ss(line);
    while(getline(ss, word, ' ')){
      while(temp -> next != nullptr){
        temp -> message = word;
        cout << temp -> cityName << " received " << word << endl;
        temp -> message = " ";
        temp = temp -> next;
      }
      temp -> message = word;
      cout << temp -> cityName;
      cout << " received " << word << endl;
      temp = head;
    }
  }
  else{
    cout << "Error reading message file" << endl;
  }
}

city *addCity(city *head, city *previousCity, string newCityName){

  city *temp = head;
  cout << previousCity -> cityName << " " << head -> cityName << endl;
  if(previousCity -> cityName != head -> cityName){
    while(temp -> cityName != previousCity -> cityName){
      if(temp -> next == nullptr){
          cout << temp -> cityName << endl;
          cout << "No matching city name found" << endl;
          break;
      }
      temp = temp -> next;
    }
  }

  city *newCity = new city(newCityName, nullptr, " ");

  if(temp -> next == nullptr){
    temp -> next = newCity;
  }
  else{
    newCity -> next = temp -> next;
    temp -> next = newCity;
  }
  return newCity;
}

int main(){

  city *head = new city(" ", nullptr, " ");
  int userChoice;

  while(userChoice != 5){
    int userChoice = promptUser();
    if(userChoice == 5){
      cout << "Goodbye!" << endl;
      return 0;
    }
    else if(userChoice == 1){
      *head = buildNetwork();
    }
    else if(userChoice == 2){
      printPath(head);
    }
    else if(userChoice == 3){
      transmitMsg(head);
    }
    else if(userChoice == 4){
      city *previousCity = new city(" ", nullptr, " ");
      string newCityName;

      cout << "Enter a City name:" << endl;
      getline(cin, newCityName);
      cout << "Enter a previous City name:" << endl;
      getline(cin, previousCity);

      addCity(head, previousCity, newCityName);
    }
    else{
      cout << "Error, input not valid, please enter a number 1-5" << endl;
      return 0;
    }
  }
}
