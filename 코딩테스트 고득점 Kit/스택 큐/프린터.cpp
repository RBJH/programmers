#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
  int answer = 0;

  queue<int> q;

  vector<int> v;

  for (int i = 0; i < priorities.size(); i++) {
    q.push(priorities[i]);
    v.push_back(priorities[i]);
  }

  sort(v.begin(), v.end());

  while (1) {
    int cur = q.front();

    q.pop();

    if (cur == v.back()) {
      answer++;

      if (!location) break;

      v.pop_back();
    } else
      q.push(cur);

    location--;

    if (location < 0) location = q.size() - 1;
  }

  return answer;
}