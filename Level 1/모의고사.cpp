#include <algorithm>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) { return a.second <= b.second; }

vector<int> solution(vector<int> answers) {
  vector<int> answer;

  int person1[5] = {1, 2, 3, 4, 5};
  int person2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
  int person3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

  vector<pair<int, int>> v;

  v.push_back(make_pair(1, 0));
  v.push_back(make_pair(2, 0));
  v.push_back(make_pair(3, 0));

  for (int i = 0; i < answers.size(); i++) {
    if (answers[i] == person1[i % 5]) v[0].second++;
    if (answers[i] == person2[i % 8]) v[1].second++;
    if (answers[i] == person3[i % 10]) v[2].second++;
  }

  sort(v.begin(), v.end(), cmp);

  answer.push_back(v[2].first);

  for (int i = 1; i >= 0; i--) {
    if (v[i].second == v[i + 1].second)
      answer.push_back(v[i].first);
    else
      break;
  }

  return answer;
}