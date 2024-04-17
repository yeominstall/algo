#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<long long>> vertices;

struct pos
{
    int x;
    int y;
};

unsigned long long GetDistance(const pos& a, const pos& b)
{
    unsigned long long x_diff = abs(a.x - b.x);
    unsigned long long y_diff = abs(a.y - b.y);
    return x_diff * x_diff + y_diff * y_diff;
}

bool isRightTriangle(const int& a, const int& b, const int& c)
{
    unsigned long long l1 = vertices[a][b];
    unsigned long long l2 = vertices[b][c];
    unsigned long long l3 = vertices[c][a];

    if (l1 + l2 == l3 || l2 + l3 == l1 || l1 + l3 == l2)
        return true;
    else
        return false;
}

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vertices.resize(n);
    for (int i = 0; i < n; ++i)
        vertices[i].resize(n);

    vector<pos> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i].x >> arr[i].y;

    // 각 점끼리의 거리
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            vertices[i][j] = GetDistance(arr[i], arr[j]);
            vertices[j][i] = vertices[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                if (isRightTriangle(i, j, k))
                    ++cnt;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}