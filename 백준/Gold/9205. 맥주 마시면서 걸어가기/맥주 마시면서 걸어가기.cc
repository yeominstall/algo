#include <iostream>
#include <vector>

using namespace std;

class pos
{
	int x;
	int y;

public:
	pos(int _x, int _y) : x(_x), y(_y) {}

	int GetDistance(const pos& to)
	{
		return abs(x - to.x) + abs(y - to.y);
	}
};

vector<pos> p;
vector<vector<int>> path;
vector<bool> visited;
int n;

bool dfs(int node, int len)
{
	if (node == n + 1)
		return true;

	for (auto& n : path[node])
	{
		if (!visited[n])
		{
			visited[n] = true;
			if (dfs(n, len + (p[node].GetDistance(p[n]))))
				return true;
		}
	}
	return false;
}

int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int TC, x, y;
	cin >> TC;
	for (int t = 0; t < TC; t++)
	{
		// input
		cin >> n;
		path.resize(n + 2);
		visited.resize(n + 2, false);
		for (int i = 0; i < n + 2; i++)
		{
			cin >> x >> y;
			p.push_back(pos(x, y));
		}
		// path-finding
		for (int i = 0; i < n + 1; i++)
		{
			for (int j = i + 1; j < n + 2; j++)
			{
				if (p[i].GetDistance(p[j]) <= 1000)
				{
					path[i].push_back(j);
					path[j].push_back(i);
				}
			}
		}

		// dfs
		if (dfs(0, 0))
			cout << "happy\n";
		else
			cout << "sad\n";

		p.clear();
		path.clear();
		visited.clear();
	}
	return 0;
}
