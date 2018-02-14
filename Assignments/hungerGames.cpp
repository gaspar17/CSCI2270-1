//Evan Spruston
//Assignment 2
//Hoenigman

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

struct word{
  string w;
  int count;
};

int getStopWords(string ignoreWordsFile, string ignoreWords[]){

  ifstream ignoreWordsStream;
  ignoreWordsStream.open(ignoreWordsFile.c_str());

  string line;
  int i = 0;
  while(getline(ignoreWordsStream, line)){

    stringstream ss;
    ss << line;
    string gotWord;

    getline(ss, gotWord);
    ignoreWords[i] = gotWord; //fill the array with stop words
    i++;

  }
  return ignoreWords[];
}

bool isStopWord(string gotWord, string ignoreWords[]){
  for(int i = 0; i < 50; i++){
    if(gotWord == ignoreWords[i]){
      return 1;
    }
  }
  return 0;
}

int arrayDouble(word *oldArray[], int length){
  int newLength = length * 2;
  word *newArray = new word[newLength];
  for(int i = 0; i < length; i++){
    newArray.w[i] = oldArray.w[i];
    newArray.count[i] = oldArray.count[i];
  }
  delete[] oldarray;
  *length = *length * 2;
  return newArray[];
}

int getNumNonStop(word words[], int length){
  int num = 0;
  for(int i = 0; i < length; i++){
    num = num + words.count[i];
  }
  return num;
}

void arraySort(word words[], int length, int topN){
  bool swapCount;

  while(swapCount != 0){
    for(int i = 1; i < length - 1; i++){
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
  printTopN(words[], topN);
}

void printTopN(word wordsSorted[], int topN){
  for(int i = 0; i < topN; i++){
    cout << wordsSorted.count[i] << " - " << wordsSorted.w[i]
  }
}

int main(int argc, char *argv[]){

  int outNum = argv[1]; //number of words to output
  string fileName = argv[2]; //name of the file to read from
  string ignoreWordsFile = argv[3]; //name of the file which contains ignored words
  string ignoreWords[50]; //ignored words array
  word *words[] = new word[100]; //stored words
  int length = 100; // length of the word array
  bool found = 0;
  int doubleCount = 0;

  ignoreWords[] = getStopWords(ignoreWordsFile, ignoreWords[]);
  ifstream getWords;
  getWords.open(fileName.c_str());

  int counter = 0;

  while(getline(getWords, line)){
    stringstream ss;
    ss << line;
    string holdWord;

    getline(ss, holdWord, ' ');
    if((isStopWord(holdWord) == 0) && (counter < length) && (counter != 0)){ //if the word isnt a stop word, the array isn't full and it isnt the first read in
      for(int i = 0; i < counter){
        if(holdWord == words.w[i]){ //check word against documented words
          words.count[i]++;
          found = 1;
        }
      }
      if(found == 0){
        words.w[counter] = holdWord;
        words.count[counter] = 1;
        counter++;
      }
      found = 0;
    }
    else if((isStopWord(holdWord) == 0) && (counter == 0)){ //for the first word read in that isnt a stop word
      words.w[counter] = holdWord;
      words.count[counter] = 1;
      counter++;
    }
    if(counter == length){
      words[] = arrayDouble(words[]);
      doubleCount++;
    }
  }

  //set all unused array components to an empty space that occurs zero times
  for(int i = counter + 1; i < length; i++){
    words.w[i] = ' ';
    words.count[i] = 0;
  }

  nonStopWords = getNumNonStop(words[], counter);
  arraySort(words[], counter, outNum);

}
