//Pointers/classes

#include <iostream>
using namespace std;

class TestScores {
    int score1, score2, score3, score4;
  public:
    void set_scores (int, int, int, int);
    int avg() {return (score1+score2+score3+score4)/4;}
};

void TestScores::set_scores (int a, int b, int c, int d) {
  score1 = a;
  score2 = b;
  score3 = c;
  score4 = d;
}

int main() {
  TestScores scores;
  int score1, score2, score3, score4;
  cout << "Enter score 1: ";
  cin >> score1;
  cout << "Enter score 2: ";
  cin >> score2;
  cout << "Enter score 3: ";
  cin >> score3;
  cout << "Enter score 4: ";
  cin >> score4;
  scores.set_scores (score1, score2, score3, score4);
  cout << "avg is: " << scores.avg();
  return 0;
}
