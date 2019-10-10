#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
  vector<int> answer;

  int a = n;
  int b = m;

  while (a % b) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }

  answer.push_back(b);
  answer.push_back(n * m / b);

  return answer;
}