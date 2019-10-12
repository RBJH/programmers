#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
  int answer = 0;

  stack<char> s;

  for (int i = 0; i < arrangement.size(); i++) {
    if (arrangement[i] == '(')
      s.push(arrangement[i]);
    else {
      s.pop();

      if (arrangement[i - 1] == ')')
        answer += 1;
      else
        answer += s.size();
    }
  }

  return answer;
}