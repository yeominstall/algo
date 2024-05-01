#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> truth;

int find_root(int x)
{
    if (x == truth[x]) return x;

    return truth[x] = find_root(truth[x]);
}

void union_root(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    if (x < y)
        truth[y] = x;
    else
        truth[x] = y;
}

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, p;
    cin >> n >> p;
    truth.resize(n + 1);
    int i, j, root = 0;
    int num_of_truth;
    cin >> num_of_truth;
    // 초기화
    for (i = 0; i <= n; ++i)
        truth[i] = i;

    // 진실을 아는 사람들의 root를 0으로 변경
    for (i = 1; i <= num_of_truth; ++i)
    {
        int ip;
        cin >> ip;
        truth[ip] = 0;
    }

    int people;
    vector<vector<int>> parties(p);
    for (i = 0; i < p; ++i)
    {
        cin >> people;
        parties[i].resize(people);
        for (j = 0; j < people; ++j)
            cin >> parties[i][j];

        // 부분집합으로 만든다
        for (j = 0; j < people - 1; ++j)
            union_root(parties[i][j], parties[i][j + 1]);
    }
    int can_join = 0;
    for (i = 0; i < p; ++i)
    {
        if (find_root(parties[i][0]) != 0)
            ++can_join;
    }

    cout << can_join << '\n';

    return 0;
}