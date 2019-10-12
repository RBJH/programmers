#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
  int answer = 0;

  unordered_map<string, int> um;

  for (auto element : clothes) {
    if (um.find(element[1]) == um.end())
      um.insert(make_pair(element[1], 1));
    else
      um[element[1]]++;
  }

  answer = 1;

  for (auto element : um) answer *= element.second + 1;

  answer--;

  return answer;
}