#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int n, m;
	int root_idx;
	int tree[50];
	int removal[50];
	memset(tree, 0, sizeof(tree));
	memset(removal, 0, sizeof(removal));
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tree[i];
		if (tree[i] == -1)
			root_idx = i;
	}
	cin >> m;

	if (m == root_idx)
		cout << "0\n";
	else if (m < n)
	{
		int d = 0;
		removal[d] = m;
		tree[m] = -2;
		while (d != -1)
		{
			int target = removal[d--];
			int cnt = 0;
			for (int i = 0; i < n && cnt < 2; i++)
			{
				if (tree[i] == target)
				{
					tree[i] = -2;
					++cnt;
					removal[++d] = i;
				}
			}
		}
		//// test
		//for (int i = 0; i < n; i++)
		//{
		//	cout << tree[i] << ' ';
		//}

		int result[50];
		for (int i = 0; i < n; i++) result[i] = 1;

		for (int i = 0; i < n; i++)
		{
			if (tree[i] == -2)
				result[i] = 0;
			else if (tree[i] >= 0)
				result[tree[i]] = 0;
		}
		int leaves_cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (result[i] > 0) leaves_cnt++;
		}
		cout << leaves_cnt << '\n';
	}

	return 0;
}