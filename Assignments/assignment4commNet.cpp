//Assignment 4
//Evan Spruston
//Hoenigman 2270

#include <iostream>
#include "assignment4commNet.h"
using namespace std;

void CommunicationNetwork::addCity(std::string, std::string){

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

  CommunicationNetwork::printNetwork();

}

void CommunicationNetwork::transmitMsg(char*){
  if(head == nullptr){
    cout << "Empty list" << endl;
  }
  City *temp  = head;
}

void CommunicationNetwork::printNetwork(){
  City *temp = head;
  cout << "===CURRENT PATH===" << endl << "NULL <- " << endl;
  while(temp -> next != nullptr){
    cout << temp -> cityName << " <-> ";
    temp = temp -> next;
  }
  cout << temp -> cityName << " -> NULL" << endl;
  cout << "==================" << endl;
}

void CommunicationNetwork::deleteCity(std::string){

}

void CommunicationNetwork::deleteNetwork(){

}
