#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int nums[8];
bool used[8];

void permu(int* former, int len)
{
	if (len == m)
	{
		for (int i = 0; i < m; i++) cout << former[i] << ' ';
		cout << '\n';
		return;
	}
	int before = -1;
	for (int i = 0; i < n; ++i)
	{
		if (used[i]) continue;
		if (before == nums[i]) continue;
		former[len] = nums[i];
		used[i] = true;
		permu(former, len + 1);
		used[i] = false;
		before = nums[i];
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
	permu(former, 0);

	return 0;
}