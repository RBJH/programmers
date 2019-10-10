#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
  bool answer = true;

  if (s.length() != 4 && s.length() != 6)
    answer = false;
  else {
    sort(s.begin(), s.end());

    answer = s[0] >= '0' && s[s.length() - 1] <= '9';
  }

  return answer;
}