#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
  int answer = 0;

  int student[32] = {
      0,
  };

  for (int i = 0; i <= n + 1; i++) student[i] = 1;

  for (int i = 0; i < lost.size(); i++) student[lost[i]]--;

  for (int i = 0; i < reserve.size(); i++) student[reserve[i]]++;

  for (int i = 1; i <= n; i++) {
    if (!student[i]) {
      if (student[i - 1] == 2) {
        student[i]++;
        student[i - 1]--;
        continue;
      }

      if (student[i + 1] == 2) {
        student[i]++;
        student[i + 1]--;
      }
    }
  }

  for (int i = 1; i <= n; i++)
    if (student[i]) answer++;

  return answer;
}