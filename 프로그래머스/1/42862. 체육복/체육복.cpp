#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int std[31];
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for (auto& i : std) i = 1;
    for (auto& i : lost) std[i] = 0;
    for (int i = 0; i < reserve.size();)
    {
        if (std[reserve[i]] == 0)
        {
            std[reserve[i]] = 1;
            reserve.erase(reserve.begin() + i);
        }
        else i++;
    }
    for (auto& i : reserve)
    {
        if (i - 1 > 0 && std[i - 1] == 0)
            std[i-1] = 1;
        else if (i < n && std[i + 1] == 0)
            std[i+1] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (std[i] == 1)
            answer++;
    }
    return answer;
}