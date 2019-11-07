#include <string>
#include <vector>

using namespace std;

int solution(string s) {
  int answer = 0;

  answer = s.length();

  for (int i = 1; i < s.length(); i++) {
    string str = "";
    string sub = s.substr(0, i);

    int cnt = 0;

    for (int j = 0; j < s.length(); j += i) {
      string cmp = s.substr(j, i);

      if (sub == cmp)
        cnt++;
      else {
        if (cnt > 1) str += to_string(cnt);

        str += sub;

        cnt = 1;

        sub = cmp;
      }
    }

    if (cnt > 1) str += to_string(cnt);

    str += sub;

    if (answer > str.length()) answer = str.length();
  }

  return answer;
}