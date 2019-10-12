#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
  int answer = 0;

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < scoville.size(); i++) pq.push(scoville[i]);

  int best, better;

  while (pq.size() > 1 && pq.top() < K) {
    answer++;

    best = pq.top();
    pq.pop();

    better = pq.top();
    pq.pop();

    pq.push(best + better * 2);
  }

  if (pq.top() < K) answer = -1;

  return answer;
}