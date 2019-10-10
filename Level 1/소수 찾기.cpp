#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;

  bool prime[1000001] = {
      false,
  };

  for (int i = 2; i < 1000000; i++) prime[i] = true;

  for (int i = 2; i < 1000; i++)
    if (prime[i])
      for (int j = i * i; j < 1000000; j += i) prime[j] = false;

  for (int i = 2; i <= n; i++)
    if (prime[i]) answer++;

  return answer;
}