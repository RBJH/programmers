#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;

  int len = progresses.size();

  stack<int> s;

  int deploy = 0;

  for (int i = 0; i < len; i++) {
    deploy = (100 - progresses[i]) / speeds[i];

    if ((100 - progresses[i]) % speeds[i]) deploy++;

    if (!s.empty()) {
      if (s.top() >= deploy)
        deploy = s.top();
      else {
        answer.push_back(s.size());

        while (!s.empty()) s.pop();
      }
    }

    s.push(deploy);
  }

  answer.push_back(s.size());

  return answer;
}