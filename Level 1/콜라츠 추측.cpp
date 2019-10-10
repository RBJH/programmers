#include <string>
#include <vector>

using namespace std;

int solution(int num) {
  int answer = 0;

  answer = -1;

  long long tmp = num;

  for (int i = 1; i <= 500; i++) {
    if (tmp == 1) {
      answer = 0;
      break;
    }

    if (tmp % 2)
      tmp = tmp * 3 + 1;
    else
      tmp /= 2;

    if (tmp == 1) {
      answer = i;
      break;
    }
  }

  return answer;
}