#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
  int answer = 0;

  priority_queue<int, vector<int>, less<int>> pq;

  int date = 0;

  for (int i = 0; i < k; i++) {
    stock--;

    if (i == dates[date] && date < dates.size()) {
      pq.push(supplies[date]);

      date++;
    }

    if (stock < 0) {
      stock += pq.top();

      pq.pop();

      answer++;
    }
  }

  return answer;
}