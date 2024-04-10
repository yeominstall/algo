#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct path
{
	int src;
	int dest;
	int cost;
};

int n, m;
vector<path> vertex;
vector<int> root;

int union_find(int node)
{
	if (root[node] == node)
		return node;
	else
		return union_find(root[node]);
}

int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	root.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vertex.push_back({ a, b, c });
	}
	for (int i = 1; i <= n; ++i)
		root[i] = i;

	sort(vertex.begin(), vertex.end(), [](const path& lval, const path& rval) { return lval.cost < rval.cost; });

	// test
	//cout << "================\n";
	//for (int i = 0; i < m; i++)
	//{
	//	cout << vertex[i].src << ' ' << vertex[i].dest << ' ' << vertex[i].cost << '\n';
	//}
	//cout << "================\n";

	// 간선끼리 유니온 파인드
	// 트리 형태 - n개의 노드로 한개의 루트를 찾을 수 있어야 한다.
	int total_cost = 0;
	for (int i = 0; i < m; ++i)
	{
		path& v = vertex[i];
		int src_root = union_find(v.src);
		int dest_root = union_find(v.dest);
		if (src_root != dest_root)
		{
			root[src_root] = dest_root;
			total_cost += v.cost;
		}
	}

	cout << total_cost << '\n';

	return 0;
}
