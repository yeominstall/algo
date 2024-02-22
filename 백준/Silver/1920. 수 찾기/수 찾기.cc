#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(const vector<int>& arr, int& n, int& key)
{
	int start = 0, end = n - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (arr[mid] == key) return 1;
		else if (arr[mid] > key)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, ip;
	vector<int> nums;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ip;
		nums.push_back(ip);
	}
	sort(nums.begin(), nums.end());
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> ip;
		cout << search(nums, n, ip) << '\n';
	}
	return 0;
}