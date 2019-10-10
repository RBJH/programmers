#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
  string answer = "";

  for (int i = 0; i < s.length(); i++) {
    if (s[i] != ' ') {
      if (s[i] <= 'Z' && s[i] + n > 'Z' || s[i] + n > 'z') s[i] -= 26;

      s[i] += n;
    }
  }

  answer = s;

  return answer;
}