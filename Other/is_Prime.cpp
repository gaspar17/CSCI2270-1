#include <iostream>
using namespace std;

void isPrime(int number){
  int count = 0;
  for(int i = 1; i < number; i++){
    if(number%i == 0){
      count++;
    }
  }
  if(count > 1){
    cout << "No";
  }
  else{
    cout << "Yes";
  }
}

/*
int main()
{
  int n,i;
  int count = 0;
  cout << "Enter an integer: " << endl;
  cin >> n;
  for(i = 1; i < n; i++){
    if(n%i == 0){
      count++;
    }
  }
  if(count > 1){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }
}
*/
