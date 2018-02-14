#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Cars{
  //Make, model, year
  string make;
  string model;
  int year;
  Cars(){}
  Cars(string ma, string mo, int y){
    make = ma;
    model = mo;
    year = y;
  }

};

int main(int argc, char *argv[]){
  //argv 1 = fileName
  //argv 2 = # of lines
  //argv 3 = fileName of Output
  Cars carArray[100];
  ifstream carStream;
  carStream.open(argv[1]);

  ofstream outfile;
  outfile.open(argv[3], ofstream::out);

  if(carStream.is_open()){
    string line;
    int counter = 0;

    while(getline(carStream, line)){
      stringstream ss;
      ss << line;
      string item;

      //get make
      getline(ss, item, ' ');
      carArray[counter].make = item;

      //get model
      getline(ss, item, ' ');
      carArray[counter].model = item;

      //get year
      getline(ss, item, ' ');
      carArray[counter].year = stoi(item);

      outfile << carArray[counter].make << "  " << carArray[counter].model << " " << carArray[counter].year << endl;

      counter++;
    }
  }
  else{
    cout << "Error loading " << argv[1] << " check file name and try again" << endl;
  }
}
