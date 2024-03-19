#include <iostream>
#include <algorithm>

using namespace std;

int lg[1000000];

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> lg[i];
    sort(lg, lg + n, [](int l, int r) {return l > r; });

    // 중간값 골라서 잘린 높이의 합 계산
    int start = 0;
    int end = lg[0];
    int highest = -1;

    while (1)
    {
        long long total = 0;
        int mid = ((long long)start + end) / 2;
        if (highest == mid)
            break;
        for (int i = 0; lg[i] > mid; i++)
        {
            int cut = lg[i] - mid;
            total += cut;
            if (total >= m) break;
        }
        if (total < m)
        {
            end = mid;
            continue;
        }
        else
        {
            start = mid;
            if (highest < mid)
                highest = mid;
        }
    }
    cout << highest << '\n';

    return 0;
}