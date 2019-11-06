#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(pair<int, float> a, pair<int, float> b) {
  if (a.second == b.second) return a.first < b.first;

  return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
  vector<int> answer;

  int fail[501] = {
      0,
  };
  int challenger[501] = {
      0,
  };

  for (int i = 0; i < stages.size(); i++) {
    fail[stages[i]]++;

    for (int j = 1; j <= stages[i]; j++) challenger[j]++;
  }

  vector<pair<int, float>> v;

  for (int n = 1; n <= N; n++) {
    if (challenger[n])
      v.push_back(make_pair(n, fail[n] / (float)challenger[n]));
    else
      v.push_back(make_pair(n, 0));
  }

  sort(v.begin(), v.end(), cmp);

  for (int i = 0; i < v.size(); i++) answer.push_back(v[i].first);

  return answer;
}