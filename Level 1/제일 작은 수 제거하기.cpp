#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
  vector<int> answer;

  answer = arr;

  sort(arr.begin(), arr.end());

  answer.erase(find(answer.begin(), answer.end(), arr[0]));

  if (answer.empty()) answer.push_back(-1);

  return answer;
}