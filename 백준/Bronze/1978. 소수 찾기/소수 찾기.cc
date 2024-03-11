#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int n, cnt = 0;
	int arr[1001];
	memset(arr, 1, sizeof(arr));
	arr[0] = arr[1] = 0;
	cin >> n;
	for (int i = 2; i <= 1000; i++)
	{
		for (int j = 2; j <= 1000; j++)
		{
			int a = i * j;
			if (a > 1000) break;
			arr[a] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (arr[input] > 0) cnt++;
	}
	cout << cnt << '\n';
	return 0;
}