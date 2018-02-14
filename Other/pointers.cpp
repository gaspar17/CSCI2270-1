//Intro to pointers
#include <iostream>
using namespace std;

int main(){

int first, second;
int * myPointer;

myPointer = &first;
*myPointer = 10;
myPointer = &second;
*myPointer = 20;

cout << "first is: " << first << endl;
cout << "second is: " << second << endl;

return 0;
}
