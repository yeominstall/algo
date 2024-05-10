#include <iostream>
#include <vector>

using namespace std;

int v, e;
vector<vector<int>> path;

int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> v >> e;
	path.resize(v + 1);
	int from, to, cost, i, j, k;
	const int base = 400 * 399 * 10000; // 1'600'000'000 - 400
	for (i = 1; i <= v; ++i)
		path[i].resize(v + 1, base + 1);

	for (i = 0; i < e; ++i)
	{
		cin >> from >> to >> cost;
		path[from][to] = cost;
	}
	for (i = 1; i <= v; ++i)
		path[i][i] = 0;

	for (i = 1; i <= v; ++i)
	{
		for (j = 1; j <= v; ++j)
		{
			if (j == i)
				continue;
			for (k = 1; k <= v; ++k)
			{
				if (k == i || j == k || path[j][i] > base || path[i][k] > base)
					continue;
				int alter = path[j][i] + path[i][k];
				if (alter < path[j][k])
					path[j][k] = alter;
			}
		}
	}

	int shortest = base + 1;
	for (i = 1; i <= v; ++i)
	{
		for (j = 1; j <= v; ++j)
		{
			if (i == j) continue;
			if (path[i][j] > base || path[j][i] > base)
				continue;
			int len = path[i][j] + path[j][i];
			if (len < shortest)
				shortest = len;
		}
	}
	if (shortest > base)
		cout << "-1\n";
	else
		cout << shortest << '\n';

	return 0;
}