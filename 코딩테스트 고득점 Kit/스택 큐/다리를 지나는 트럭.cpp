#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int answer = 0;

  answer = 1;

  queue<pair<int, int>> q;

  int cur = 0;

  q.push(make_pair(truck_weights[cur], answer));

  int w = truck_weights[cur];

  cur++;

  while (!q.empty()) {
    answer++;

    if (answer >= q.front().second + bridge_length) {
      w -= q.front().first;

      q.pop();
    }

    if (cur < truck_weights.size()) {
      if (w + truck_weights[cur] > weight) continue;

      q.push(make_pair(truck_weights[cur], answer));

      w += truck_weights[cur];

      cur++;
    }
  }

  return answer;
}