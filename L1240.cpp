//Lecture Code 1/24/18, 1/26
#include <iostream>
using namespace std;

void passByValue(int a){

  a++;

}

void passByPointer(int *ptr){

  cout << "address stored in ptr: " << ptr << endl;
  *ptr = *ptr + 1;

}

void passByReference(int &a){

  a++;

}

void passByArray(int *a){ // can also call with passByArray(int a[]))

  a[0] = 10;
  a[1] = 11;

}

int main(){

  int a = 5; //regular variable
  cout << &a << endl;

  //pointer and address it points to must be of same type
  int *b = &a; //b is a pointer, stores address of a
  //* has two meaings: used to declare pointers and dereference the pointer
  //dereferencing goes to address stored in the pointer and retrieves the value at that address
  cout << &b /* address of b */ << ", " << b /*value stored in b */ << ", " << *b /* value stored in the value stored in b*/ << endl;

  a = 10; //value for *b will change with a

  cout << *b << endl;

  int c = 20;
  b = &c;
  cout << *b << endl;

  int arrayA[5];
  cout << arrayA << endl; //name of the array gives address of first element in array

  passByValue(a);
  cout << a << endl; //a is unchanged

  cout << "address stored in b: " << b << endl;

  passByPointer(b);
  cout << *b << endl; //updates the value head in the address stored in b which is the same one referenced in main

  //a is passed as 10
  passByReference(a); //a is a regular var not a pointer
  cout << a << endl;

  for(int i = 0; i < 5; i++){
    arrayA[i]=0;
  }

  passByArray(arrayA);

  for(int i = 0; i < 5; i++){
    cout << arrayA[i] << endl;
  }

  //Stack - finite amount of memory used to control program execution
  //local variables stored here
  //fast
  //memory management done for you
  //relatively small
  //int a[stoi(argv[1])]
  //cin
  //These overutalize stack memory

  //heap - large pool of memory, much larger than the Stack
  //large data structures should rely on heap  instead of Stack
  //better for allocation during runtime (i.e. cin or argv)
  //dynamic memory allocation

  //dynamically allocate an array
  //new used to allocate memory on the heap
  //have to use a pointer to access heap memory
  //y is a pointer to an array of 10 ints
  //y is a stack variable pointing to a variable on the heap

  int *y = new int[10];
  double *x = new double[20]; //array of 20 doubles stored in heap

  //for every new you need a delete in order to free the memory back up

  delete[] y; //frees the memory allocated to y
  delete[] x; //frees the memory allocated to x

  int *x2 = new int;
  *x2 = 5;
  y = x2; //y now points to same address as x2
  cout << *y << endl;

  //x = x2; //this doesnt work since the data types dont match
  //programs can slow down over time

  int *x3 = new int[100]; //x3 points to array of 100 ints
  x3[0] = 100;
  x3[10] = 200;
  x3 = x2;
  //how do you get data out of x3
  //you cannot get back to x3 to clear the data it pointed to
  //array of 100 ints is stuck in memory and cannot be accessed
  //memory leak


}
