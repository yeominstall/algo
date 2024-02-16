#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 그리디가 최적해가 되는 경우: 부분의 최적해가 결국 전체의 최적해가 될 때
// 순차 순회가 되어야 한다. 문제를 잘 읽을 것
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    unordered_map<int, int> lost_hash;
    sort(reserve.begin(), reserve.end());
    for (auto& i : lost) lost_hash[i]++;
    for (auto iter = reserve.begin(); iter != reserve.end(); )
    {
        if (lost_hash[*iter] > 0)
        {
            lost_hash.erase(*iter);
            reserve.erase(iter);
            answer++;
        }
        else
            iter++;
    }
    for (auto& i : reserve)
    {
        if (lost_hash[i-1] > 0)
        {
            lost_hash.erase(i-1);
            answer++;
        }
        else if (lost_hash[i+1] > 0)
        {
            lost_hash.erase(i+1);
            answer++;
        }
    }
    return answer;
}