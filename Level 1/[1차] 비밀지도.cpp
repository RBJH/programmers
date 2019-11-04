#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
  vector<string> answer;

  vector<string> map1, map2;

  for (int i = 0; i < n; i++) {
    int tmp1 = arr1[i];
    int tmp2 = arr2[i];

    string str1 = "";
    string str2 = "";

    for (int j = 0; j < n; j++) {
      if (tmp1 % 2)
        str1 += "#";
      else
        str1 += " ";

      if (tmp2 % 2)
        str2 += "#";
      else
        str2 += " ";

      tmp1 /= 2;
      tmp2 /= 2;
    }

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    map1.push_back(str1);
    map2.push_back(str2);
  }

  for (int i = 0; i < n; i++) {
    string str = "";

    for (int j = 0; j < n; j++) {
      if (map1[i][j] == '#' || map2[i][j] == '#')
        str += "#";
      else
        str += " ";
    }

    answer.push_back(str);
  }

  return answer;
}