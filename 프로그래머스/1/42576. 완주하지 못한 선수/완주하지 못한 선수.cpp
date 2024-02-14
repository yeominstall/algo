#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 선수의 이름을 key로 사용하는 해시 테이블을 사용하면 상수시간에 접근할 수 있다.
// key : value = 선수 이름 : 접근 횟수
string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> h;
    for (auto &i : participant) h[i]++;
    for (auto &i : completion) h[i]--;
    for (auto &i : h)
        if (i.second > 0)
            return i.first;
}