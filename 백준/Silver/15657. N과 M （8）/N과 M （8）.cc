#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int nums[8];

void permu(int* former, int len, int begin)
{
	if (len == m)
	{
		for (int i = 0; i < m; i++) cout << former[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = begin; i < n; ++i)
	{
		former[len] = nums[i];
		permu(former, len + 1, i);
	}
}

int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	sort(nums, nums + n);
	int former[8];
	permu(former, 0, 0);

	return 0;
}