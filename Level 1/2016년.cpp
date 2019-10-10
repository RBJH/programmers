#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
  string answer = "";

  int date = 0;

  string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

  switch (a) {
    case 12:
      date += 30;
    case 11:
      date += 31;
    case 10:
      date += 30;
    case 9:
      date += 31;
    case 8:
      date += 31;
    case 7:
      date += 30;
    case 6:
      date += 31;
    case 5:
      date += 30;
    case 4:
      date += 31;
    case 3:
      date += 29;
    case 2:
      date += 31;
  }

  date += b - 1 + 5;

  answer = day[date % 7];

  return answer;
}