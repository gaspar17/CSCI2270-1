//Assignment 4
//Evan Spruston
//Hoenigman 2270

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "CommunicationNetwork.h"
using namespace std;

CommunicationNetwork::CommunicationNetwork(){

}

CommunicationNetwork::~CommunicationNetwork(){

}

void CommunicationNetwork::addCity(std::string newCityName, std::string previousCityName){
  if(previousCityName == "First"){
    City *newCity = new City(newCityName, head, nullptr, " ");
    head = newCity;
  }
  else if(previousCityName == "" || previousCityName == tail -> cityName){
    City *newCity = new City(newCityName, nullptr, tail, " ");
    tail = newCity;
  }
  else{
    City *temp = head;
    while(temp -> cityName != previousCityName){
      if(temp -> next == nullptr){
          cout << temp -> cityName << endl;
          cout << "No matching city name found" << endl;
          break;
      }
      temp = temp -> next;
    }
    City *newCity = new City(newCityName, temp -> next, temp, " ");
    temp -> next -> previous = newCity;
    temp -> next = newCity;
  }
}

void CommunicationNetwork::printNetwork(){
  City *temp = head;
  cout << "===CURRENT PATH===" << endl << "NULL <- ";
  while(temp -> next != nullptr){
    cout << temp -> cityName << " <-> ";
    temp = temp -> next;
  }
  cout << temp -> cityName << " -> NULL" << endl << "==================" << endl;
}

void CommunicationNetwork::buildNetwork(){

  City *head = new City(" ", nullptr, nullptr, " ");
  City *Bos = new City("Boston", nullptr, nullptr, " ");
  City *NY = new City("New York", Bos, nullptr, " ");
  City *WashDC = new City("Washington, D.C.", NY, nullptr, " ");
  City *Atl = new City("Atlanta", WashDC, nullptr, " ");
  City *Chi = new City("Chicago", Atl, nullptr, " ");
  City *StL = new City("St. Louis", Chi, nullptr, " ");
  City *Dal = new City("Dallas", StL, nullptr, " ");
  City *Den = new City("Denver", Dal, nullptr, " ");
  City *Pho = new City("Phoenix", Den, nullptr, " ");
  City *LA = new City("Los Angeles", Pho, nullptr, " ");

  Pho -> previous = LA;
  Den -> previous = Pho;
  Dal -> previous = Den;
  StL -> previous = Dal;
  Chi -> previous = StL;
  Atl -> previous = Chi;
  WashDC -> previous = Atl;
  NY -> previous = WashDC;
  Bos -> previous = NY;

  head = LA;
  tail = Bos;

  //CommunicationNetwork::printHeadTail();

  CommunicationNetwork::printNetwork();
  /*City *temp = head;
  cout << "===CURRENT PATH===" << endl << "NULL <- ";
  while(temp -> next != nullptr){
    cout << temp -> cityName << " <-> ";
    temp = temp -> next;
  }
  cout << temp -> cityName << " -> NULL" << endl << "==================" << endl;
  */
}

void CommunicationNetwork::transmitMsg(char* filename){
  if(head == nullptr){
    cout << "Empty list" << endl;
    return;
  }
  City *temp  = head;

  ifstream messageStream;
  string line;
  string word;
  messageStream.open(filename);

  if(messageStream.is_open()){
    getline(messageStream, line);
    stringstream ss(line);
    while(getline(ss, word, ' ')){
      while(temp -> next != nullptr){
        temp -> message = word;
        cout << temp -> cityName << " received " << temp -> message << endl;
        temp -> message = " ";
        temp = temp -> next;
      }
      temp -> message = word;
      cout << temp -> cityName << " received " << temp -> message << endl;
      temp = head;
    }
  }
  else{
    cout << "Error reading message file" << endl;
  }
}

void CommunicationNetwork::deleteCity(std::string removeCity){
  City *temp = head;
  while(temp -> cityName != removeCity){
    if(temp -> next == nullptr){
        cout << temp -> cityName << endl;
        cout << "No matching city name found" << endl;
        break;
    }
    temp = temp -> next;
  }
  temp -> previous -> next = temp -> next;
  temp -> next -> previous = temp -> previous;
  delete[] temp;
}

void CommunicationNetwork::deleteNetwork(){
  City *temp = head -> next;
  while(temp != nullptr){
    delete[] temp -> previous;
    temp = temp -> next;
  }
  delete[] tail;
  head = NULL;
}

void CommunicationNetwork::printHeadTail(){
  cout << head -> cityName << endl;
  cout << tail -> cityName << endl;
}
