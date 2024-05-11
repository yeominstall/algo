#include <iostream>
#include <vector>

using namespace std;

int n, m, r;
vector<vector<int>> paths;
vector<int> items;

int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> m >> r;
	const int base = 15 * r + 1;
	paths.resize(n + 1, vector<int>(n + 1, base));
	items.resize(n + 1);
	int i, j, k;
	for (i = 1; i <= n; ++i)
	{
		cin >> items[i];
		paths[i][i] = 0;
	}
	int from, to, len;
	for (i = 0; i < r; ++i)
	{
		cin >> from >> to >> len;
		if (len < paths[from][to])
		{
			paths[from][to] = len;
			paths[to][from] = len;
		}
	}

	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			if (j == i) continue;
			for (k = 1; k <= n; ++k)
			{
				if (k == i || j == k || paths[j][i] == base || paths[i][k] == base) continue;
				int alter = paths[j][i] + paths[i][k];
				if (alter < paths[j][k])
					paths[j][k] = alter;
			}
		}
	}
	int curr, max_item = -1;
	for (i = 1; i <= n; ++i)
	{
		curr = 0;
		for (j = 1; j <= n; ++j)
		{
			if (paths[i][j] <= m)
				curr += items[j];
		}
		if (max_item < curr)
			max_item = curr;
	}

	cout << max_item << '\n';
	return 0;
}