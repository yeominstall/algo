#include <iostream>
#include <cstring>

using namespace std;
#define _R 10007

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int tmp[10];
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int add = 0;
		for (int j = 0; j < 10; j++)
		{
			add = (add + arr[j]) % 10007;
			tmp[j] = add;
		}
		memcpy(arr, tmp, sizeof(arr));
	}
	int res = 0;
	for (int i = 0; i < 10; i++)
	{
		res = (res + arr[i]) % _R;
	}
	cout << res << '\n';

	return 0;
}