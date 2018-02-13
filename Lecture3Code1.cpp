#include <iostream>
using namespace std;

//command line args are arguments to the main function which runs when the program runs
int main(int argc, char *argv[]){
  //argc is the number of arguments
  //argv is the array of pointers to the arguments

  cout << "Hello World" << endl;
  cout << argc << endl;
  //argv[0] is the name of the running program
  //cout << argv[0] << endl;
  //other passed arguments get added to unused indicies of argv[]
  //cout << argv[1] << endl;

  for(int i = 0; i < argc; i++){ //loop through arguments to avoid having to know how many arguments you have ahead of time
    cout << argv[i] << endl;
  }


}
