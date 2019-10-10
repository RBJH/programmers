#include <iostream>
#include <string>
using namespace std;

bool solution(string s) {
  bool answer = true;

  int cntp = 0;
  int cnty = 0;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'p' || s[i] == 'P') cntp++;
    if (s[i] == 'y' || s[i] == 'Y') cnty++;
  }

  answer = cntp == cnty;

  return answer;
}