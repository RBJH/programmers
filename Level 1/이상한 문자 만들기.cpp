#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  string answer = "";

  int index = 0;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ')
      index = 0;
    else {
      if (index % 2) {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 'a' - 'A';
      } else if (s[i] >= 'a' && s[i] <= 'z')
        s[i] += 'A' - 'a';

      index++;
    }

    answer += s[i];
  }

  return answer;
}