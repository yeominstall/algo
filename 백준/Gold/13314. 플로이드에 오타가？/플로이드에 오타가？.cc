#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int n = 100; // or 99
	vector<vector<int>> paths(n + 1, vector<int>(n + 1, 10));
	int i, j;
	for (i = 1; i <= n; ++i)
		paths[i][i] = 0;
	// 경유지가 n 인 경우를 고려하지 않을 경우, 9700개 이상의 오류가 발생
	// n 을 경유하면 경로가 짧아져야 한다.
	// paths[j][k] > paths[j][n] + paths[n][k] 가 항상 성립하도록
	// paths[j][n], paths[n][k] = 0;
	for (i = 1; i <= n; ++i)
	{
		paths[i][n] = 0;
		paths[n][i] = 0;
	}

	cout << n << '\n';
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
			cout << paths[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}