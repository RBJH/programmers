#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
  int answer = 0;

  vector<int> v;

  for (int i = 0; i < dartResult.length(); i++) {
    if (dartResult[i] >= '0' && dartResult[i] <= '9') {
      if (dartResult[i] == '1' && dartResult[i + 1] == '0') {
        v.push_back(10);

        i++;
      } else
        v.push_back(dartResult[i] - '0');
    }

    if (dartResult[i] == 'D') v[v.size() - 1] *= v[v.size() - 1];
    if (dartResult[i] == 'T')
      v[v.size() - 1] *= v[v.size() - 1] * v[v.size() - 1];

    if (dartResult[i] == '*') {
      v[v.size() - 1] *= 2;

      if (v.size() > 1) v[v.size() - 2] *= 2;
    }
    if (dartResult[i] == '#') v[v.size() - 1] = -v[v.size() - 1];
  }

  for (int i = 0; i < v.size(); i++) answer += v[i];

  return answer;
}