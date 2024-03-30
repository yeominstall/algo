#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	vector<unordered_map<int, int>> path;
	path.push_back({});	// 0번째 도시는 없다
	int n, m;
	cin >> n >> m;
	path.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		if (path[start].find(end) == path[start].end() || path[start][end] > cost)
			path[start][end] = cost;
	}
	int dpt, arv;
	cin >> dpt >> arv;

	queue<int> cheapest;
	cheapest.push(dpt);

	vector<long long> visited;
	visited.resize(n + 1, -1);
	visited[dpt] = 0;
	
	while (cheapest.size() > 0)
	{
		int cur = cheapest.front();
		for (auto& p : path[cur])
		{
			if (visited[p.first] == -1 || visited[p.first] > visited[cur] + p.second)
			{
				visited[p.first] = visited[cur] + p.second;
				cheapest.push(p.first);
			}
		}
		cheapest.pop();
	}
	cout << visited[arv] << '\n';

	return 0;
}