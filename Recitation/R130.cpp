//Recitation 3 Code 1/30

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int resizeArray(int *oldArray, int *length){
  int newLength = *length * 2;
  int *newArray = new int[newLength];
  for(int i=0; i < *length; i++){
    newArray[i] = oldArray[i];
  }
  delete[] oldArray;
  oldArray = newArray;
  *length = newLength;
}

int main(int argc, char* argv[]){

  string fileName = argv[1];
  ifstream numStream;
  numStream.open(fileName.c_str());
  int length = 10;
  int *numArray = new int[10];
  string val;
  int counter = 0;

  if(numStream.is_open()){
    while(getline(numStream, val)){
      toBeInserted = getline(numStream, val);
      if(counter == length - 1){
        resizeArray(numArray, length);
      }
      numArray[counter] = toBeInserted;
      counter++;
    }
  }
  else{
    cout << "Error loading file" << endl;
  }


  return 0;
}
