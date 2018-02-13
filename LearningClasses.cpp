//Learning Classes

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
  int a, b, c, d;
  cout << "Enter score 1: ";
  cin >> a;
  cout << "Enter score 2: ";
  cin >> b;
  cout << "Enter score 3: ";
  cin >> c;
  cout << "Enter score 4: ";
  cin >> d;
  scores.set_scores (a, b, c, d);
  cout << "avg is: " << scores.avg();
  return 0;
}
