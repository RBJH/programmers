#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
  int answer = 0;

  bool is_learned[26] = {
      false,
  };

  bool flag = false;

  for (int i = 0; i < skill_trees.size(); i++) {
    for (int l = 0; l < skill.length(); l++) is_learned[l] = false;

    flag = true;

    for (int j = 0; j < skill_trees[i].length(); j++) {
      if (find(skill.begin(), skill.end(), skill_trees[i][j]) != skill.end()) {
        if (find(skill.begin(), skill.end(), skill_trees[i][j]) -
                skill.begin() &&
            !is_learned[find(skill.begin(), skill.end(), skill_trees[i][j]) -
                        skill.begin() - 1]) {
          flag = false;
          break;
        }

        is_learned[find(skill.begin(), skill.end(), skill_trees[i][j]) -
                   skill.begin()] = true;
      }
    }

    if (flag) answer++;
  }

  return answer;
}