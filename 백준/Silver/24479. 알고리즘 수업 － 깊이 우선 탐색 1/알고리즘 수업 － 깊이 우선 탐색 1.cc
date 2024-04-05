#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r;
int seq = 1;
vector<vector<int>> graph;
vector<int> visited;

void dfs(int next)
{
	for (auto& n : graph[next])
	{
		if (visited[n] == 0)
		{
			visited[n] = ++seq;
			dfs(n);
		}
	}
}

int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> m >> r;
	graph.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	for (auto& node : graph)
		sort(node.begin(), node.end());

	visited.resize(n + 1, 0);
	visited[r] = seq;
	dfs(r);

	for (int i = 1; i <= n; i++)
		cout << visited[i] << '\n';

	return 0;
}
