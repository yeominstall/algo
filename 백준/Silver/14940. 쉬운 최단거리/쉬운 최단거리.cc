#include <iostream>
#include <queue>

using namespace std;

int land[1000][1000];

struct pos
{
    int x;
    int y;
};

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    pos goal;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int input;
            cin >> input;
            if (input == 2)
            {
                goal = { j, i };
                land[i][j] = 0;
            }
            else
                land[i][j] = -input;
        }

    queue<pos> path;
    path.push(goal);
    while (path.size() != 0)
    {
        pos target = path.front();
        path.pop();
        int pathval = land[target.y][target.x] + 1;
        for (int d = 0; d < 4; d++)
        {
            int dx = target.x;
            int dy = target.y;
            if (d == 0 && (--dy) < 0)
                continue;
            else if (d == 1 && (++dy) >= n)
                continue;
            else if (d == 2 && (--dx) < 0)
                continue;
            else if (d == 3 && (++dx) >= m)
                continue;

            // udlr이 갈 수 없는 땅이면 continue
            if (land[dy][dx] == 0)
                continue;
            
            if (land[dy][dx] == -1 || pathval < land[dy][dx])
            {
                land[dy][dx] = pathval;
                path.push({ dx, dy });
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << land[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}