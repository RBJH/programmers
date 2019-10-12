#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool cmp_a(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }

bool cmp_b(pair<string, vector<pair<int, int>>> a,
           pair<string, vector<pair<int, int>>> b) {
  int plays_a = 0;
  int plays_b = 0;

  for (int i = 0; i < a.second.size(); i++) plays_a += a.second[i].second;

  for (int i = 0; i < b.second.size(); i++) plays_b += b.second[i].second;

  return plays_a > plays_b;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> answer;

  unordered_map<string, vector<pair<int, int>>> um;

  int len = genres.size();

  for (int i = 0; i < len; i++) {
    if (um.find(genres[i]) == um.end()) {
      vector<pair<int, int>> v;

      v.push_back(make_pair(i, plays[i]));

      um.insert(make_pair(genres[i], v));
    } else
      um[genres[i]].push_back(make_pair(i, plays[i]));
  }

  vector<pair<string, vector<pair<int, int>>>> v;

  for (auto element : um) {
    sort(element.second.begin(), element.second.end(), cmp_a);

    v.push_back(element);
  }

  sort(v.begin(), v.end(), cmp_b);

  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].second.size(); j++) {
      if (j > 1) break;

      answer.push_back(v[i].second[j].first);
    }
  }

  return answer;
}