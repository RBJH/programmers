#include <string>
#include <vector>

using namespace std;

string solution(int n) {
  string answer = "";

  for (int i = 0; i < n; i++) {
    if (n % 2)
      answer += "박";
    else
      answer += "수";
  }

  return answer;
}