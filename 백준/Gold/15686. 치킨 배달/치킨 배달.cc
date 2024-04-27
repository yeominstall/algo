#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct pos
{
    int x;
    int y;
};

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<unsigned int>> town(n);
    vector<pos> house;
    vector<pos> chickens;
    for (int i = 0; i < n; ++i)
    {
        town[i].resize(n);
        for (int j = 0; j < n; ++j)
        {
            cin >> town[i][j];
            if (town[i][j] == 1)
                house.push_back({ i, j });
            else if (town[i][j] == 2)
                chickens.push_back({ i, j });
        }
    }

    int chicken_cnt = chickens.size();
    int sample = chicken_cnt - m; // 전체 치킨집 수 - 남길 치킨집 수 = 폐업시킬 치킨집 수
    vector<bool> comb(chicken_cnt, true);
    int min_dist = INT_MAX;
    // 폐업시킬 수 뽑기
    if (sample < m)
    {
        for (int i = 0; i < m; ++i)
            comb[i] = false;

        // true 면 폐업
        do
        {
            int dist = 0;
            for (int i = 0; i < house.size(); ++i)
            {
                int shortest_from_i = INT_MAX;
                auto& hx = house[i].x;
                auto& hy = house[i].y;
                for (int j = 0; j < chickens.size(); ++j)
                {
                    auto& cx = chickens[j].x;
                    auto& cy = chickens[j].y;
                    if (!comb[j])
                    {
                        // 치킨 거리 구하기
                        int to_j = (abs(hx - cx) + abs(hy - cy));
                        shortest_from_i = min(shortest_from_i, to_j);
                        if (shortest_from_i == 1) break;
                    }
                }
                dist += shortest_from_i;
            }
            min_dist = min(min_dist, dist);
        } while (next_permutation(comb.begin(), comb.end()));
    }
    else // 남길 치킨집 수 뽑기
    {
        for (int i = 0; i < sample; ++i)
            comb[i] = false;

        // true 면 생존
        do
        {
            int dist = 0;
            for (int i = 0; i < house.size(); ++i)
            {
                int shortest_from_i = INT_MAX;
                auto& hx = house[i].x;
                auto& hy = house[i].y;
                for (int j = 0; j < chickens.size(); ++j)
                {
                    auto& cx = chickens[j].x;
                    auto& cy = chickens[j].y;
                    if (comb[j])
                    {
                        // 치킨 거리 구하기
                        int to_j = (abs(hx - cx) + abs(hy - cy));
                        shortest_from_i = min(shortest_from_i, to_j);
                        if (shortest_from_i == 1) break;
                    }
                }
                dist += shortest_from_i;
            }
            min_dist = min(min_dist, dist);
        } while (next_permutation(comb.begin(), comb.end()));
    }

    cout << min_dist << '\n';

    return 0;
}