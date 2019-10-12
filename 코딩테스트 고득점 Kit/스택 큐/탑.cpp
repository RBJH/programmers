#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
  vector<int> answer;

  answer.push_back(0);

  bool flag = false;

  for (int i = 1; i < heights.size(); i++) {
    flag = true;

    for (int j = i - 1; j >= 0; j--) {
      if (heights[j] > heights[i]) {
        answer.push_back(j + 1);

        flag = false;
        break;
      }
    }

    if (flag) answer.push_back(0);
  }

  return answer;
}