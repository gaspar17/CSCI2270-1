//Test

#include <iostream>

using namespace std;

struct word{
  

}

int main(){

  bool swapCount;
  int slotMatchLeft = 1;
  int slotMatchRight = length - 1;

  while(swapCount != 0){
    for(int i = slotMatchLeft; i < slotMatchRight; i++){
      swapCount = 0;
      if(words.count[i-1] < words.count[i]){ //if left value is lower than middle value
        word holdLeft = words[i-1]; //store the left value
        word holdRight = words[i]; //store the right value
        words[i-1] = holdRight;
        words[i] = holdLeft;
        swapCount = 1;
      }
      if(words.count[i+1] > words.count[i]){
        holdLeft = words[i];
        holdRight = words[i+1];
        words[i] = holdRight;
        words[i+1] = holdLeft;
        swapCount = 1;
      }
      if(words.count[i+1] > words.count[i]){
        holdLeft = words[i];
        holdRight = words[i+1];
        words[i] = holdRight;
        words[i+1] = holdLeft;
        swapCount = 1;
      }
      if(words.count[i-1] < words.count[i]){ //if left value is lower than middle value
        word holdLeft = words[i-1]; //store the left value
        word holdRight = words[i]; //store the right value
        words[i-1] = holdRight;
        words[i] = holdLeft;
        swapCount = 1;
      }
    }

  }

}
