//FizzBuzz
#include <iostream>
using namespace std;

/*
int main()
{
	int i=1;
	while (i <= 100){
		if (i % 3 == 0){
			cout << "Fizz";
		}
		if (i % 5 == 0){
			cout << "Buzz";
		}
		else if (i % 3 != 0 && i % 5 != 0) {
			cout << i;
		}
		cout << endl;
		i++;
	}
	return 0;
}
*/

int main(){
	int i = 1;
	while (i<=100){
		if (i % 3 == 0 && i % 5 == 0){
			cout << "FizzBuzz" << endl;
		}
		else if (i % 3 == 0){
			cout << "Fizz" << endl;
		}
		else if (i % 5 == 0){
			cout << "Buzz" << endl;
		}
		else {
			cout << i << endl;
		}
		i++;
	}
	return 0;
}
