#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char canvas[100][100];
bool visited[100][100];
int n;

struct pos
{
	int x;
	int y;
};

void bfs(int x, int y, const char color)
{
	queue<pos> target;
	target.push({ x, y });
	while (target.size() > 0)
	{
		pos curr = target.front();
		target.pop();
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
			else if (d == 3 && (++dx) >= n)
				continue;
			if (!visited[dy][dx])
			{
				if (canvas[dy][dx] == color 
					|| (color == 'Y' && (canvas[dy][dx] == 'R' || canvas[dy][dx] == 'G')))
				{
					visited[dy][dx] = true;
					target.push({ dx, dy });
				}
			}
		}
	}
}

int main(void)
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> canvas[i][j];

	int rgcount = 0, count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == false)
			{
				count++;
				bfs(j, i, canvas[i][j]);
			}
		}
	}

	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == false)
			{
				rgcount++;
				if (canvas[i][j] == 'B')
					bfs(j, i, canvas[i][j]);
				else
					bfs(j, i, 'Y');
			}
		}
	}

	cout << count << ' ' << rgcount << '\n';

	return 0;
}