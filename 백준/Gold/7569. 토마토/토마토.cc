#include <iostream>
#include <queue>

using namespace std;
short grid[100][100][100]; // 2: 순회 완료, 1: 순회 대상, 0: 안익음, -1: 빈칸
short visited[100][100][100];
int n, m, h;

void printall(void)
{
	for (short i = 0; i < h; i++)
	{
		for (short j = 0; j < n; j++)
		{
			for (short k = 0; k < m; k++)
				cout << grid[i][j][k] << ' ';
			cout << '\n';
		}
		cout << "---------\n";
	}
	cout << "=======================================\n";
}

struct pos
{
	int x;
	int y;
	int z;
	int cycle;
};

int main(void)
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin >> m >> n >> h;
	int target_count = 0;
	int premature_count = 0;
	queue<pos> target;
	for (short i = 0; i < h; i++)
		for (short j = 0; j < n; j++)
			for (short k = 0; k < m; k++)
			{
				cin >> grid[i][j][k];
				if (grid[i][j][k] == 1)
				{
					target.emplace(pos{ k, j, i, 0 });
					target_count++;
				}
				else if (grid[i][j][k] == 0)
					premature_count++;
			}

	if (premature_count < 1)
	{
		cout << "0\n";
		return 0;
	}

	int cycle = 0;
	while (target.size() > 0)
	{
		pos cur = target.front();
		target.pop();
		cycle = cur.cycle + 1;
		if (visited[cur.z][cur.y][cur.x] == cycle) continue;
		for (int d = 0; d < 6; d++)
		{
			int dz = cur.z;
			int dy = cur.y;
			int dx = cur.x;
			if (d == 0)
			{
				dy--;
				if (dy < 0) continue;
			}
			else if (d == 1)
			{
				dy++;
				if (dy >= n) continue;
			}
			else if (d == 2)
			{
				dx--;
				if (dx < 0) continue;
			}
			else if (d == 3)
			{
				dx++;
				if (dx >= m) continue;
			}
			else if (d == 4)
			{
				dz--;
				if (dz < 0) continue;
			}
			else if (d == 5)
			{
				dz++;
				if (dz >= h) continue;
			}
			if (grid[dz][dy][dx] == 0)
			{
				target.push({ dx, dy, dz, cycle });
				grid[dz][dy][dx] = 1;
				visited[dz][dy][dx] = cycle;
				target_count++;
				premature_count--;
			}
		}
		grid[cur.z][cur.y][cur.x] = 2;
		visited[cur.z][cur.y][cur.x] = cycle;
		target_count--;
		//printall();
	}
	if (premature_count > 0)
		cout << "-1\n";
	else
		cout << cycle - 1 << '\n';

	return 0;
}