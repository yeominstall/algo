#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int tc, n, m;
	bool doc[10][500];
	int counter[10];
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		cin >> n >> m;
		int target = 0;
		memset(doc, false, sizeof(doc));
		memset(counter, 0, sizeof(counter));
		for (int d = 0; d < n; d++)
		{
			int priority;
			cin >> priority;
			doc[priority][d] = true;
			if (d == m) target = priority;
			counter[priority]++;
		}
		int cnt = 0;
		int last_key = 0;
		// 더 높은 우선순위 문서들 count
		for (int i = 9; i > target; i--)
		{
			if (counter[i] == 0) continue;
			cnt += counter[i];

			// 마지막 인덱스 구하기
			for (int j = 1; j <= 100; j++)
			{
				int idx = (100 + last_key - j) % 100;
				if (doc[i][idx])
				{
					last_key = idx;
					break;
				}
			}
		}
		// last key ~ end() + begin() ~ m
		for (int i = 0; i < 100; i++)
		{
			int idx = (last_key + i) % 100;
			if (doc[target][idx])
			{
				cnt++;
				if (idx == m) break;
			}
		}
		
		cout << cnt << '\n';
	}

	return 0;
}