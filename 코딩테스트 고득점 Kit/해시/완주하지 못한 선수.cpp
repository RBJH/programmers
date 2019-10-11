#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
  string answer = "";

  unordered_map<string, int> um;

  for (auto element : completion) {
    if (um.find(element) == um.end())
      um.insert(make_pair(element, 1));
    else
      um[element]++;
  }

  for (auto element : participant) {
    if (um.find(element) == um.end() || !um[element]) {
      answer = element;
      break;
    }

    um[element]--;
  }

  return answer;
}