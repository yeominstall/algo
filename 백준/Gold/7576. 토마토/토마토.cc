#include <iostream>
#include <queue>

using namespace std;
short grid[1000][1000]; // 2: 순회 완료, 1: 순회 대상, 0: 안익음, -1: 빈칸
short visited[1000][1000];
int n, m;

struct pos
{
	int x;
	int y;
	int cycle;
};

int main(void)
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin >> m >> n;
	queue<pos> target;
	int premature_count = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 1)
				target.push({ j, i, 0 });
			else if (grid[i][j] == 0) premature_count++;
		}

	int cycle = 0;
	while (target.size() > 0)
	{
		pos curr = target.front();
		target.pop();
		cycle = curr.cycle + 1;
		// up, down, left, right
		for (int d = 0; d < 4; d++)
		{
			int dx = curr.x;
			int dy = curr.y;
			if (d == 0 && (--dy) < 0)
				continue;
			else if (d == 1 && (++dy) >= n)
				continue;
			else if (d == 2 && (--dx) < 0)
				continue;
			else if (d == 3 && (++dx) >= m)
				continue;

			if (grid[dy][dx] == 0 && visited[dy][dx] < cycle)
			{
				grid[dy][dx] = 1;
				target.push({ dx, dy, cycle });
				visited[dy][dx] = cycle;
				premature_count--;
			}
		}
		grid[curr.y][curr.x] = 2;
	}

	if (premature_count > 0)
		cout << "-1\n";
	else
		cout << cycle - 1 << '\n';

	return 0;
}