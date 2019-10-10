#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
  long long answer = 0;

  vector<int> v;

  while (n) {
    v.push_back(n % 10);

    n /= 10;
  }

  sort(v.begin(), v.end(), greater<int>());

  int i = 1;

  while (!v.empty()) {
    answer += v.back() * i;

    v.pop_back();

    i *= 10;
  }

  return answer;
}