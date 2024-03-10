#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int all[500000];
int freq[8001];
int main(void)
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		all[i] = input;
		total += input;
		freq[input + 4000]++;
	}

	sort(all, all + n);
	// 산술평균
	int dived = (total / (double)n) * 10;
	if (abs(dived % 10) >= 5)
	{
		if (dived < 0)
			dived = (dived / 10) - 1;
		else
			dived = (dived / 10) + 1;
	}
	else
		dived /= 10;
	cout << dived << '\n';

	// 중앙값
	cout << all[n / 2] << '\n';

	// 최빈값
	int mv = -1, max_idx = -1, no = 0;
	for (int i = all[0] + 4000; i <= (all[n-1] + 4000); i++)
	{
		if (mv < freq[i])
		{
			mv = freq[i];
			max_idx = i;
			no = 1;
		}
		else if (mv == freq[i] && no < 2)
		{
			max_idx = i;
			no++;
		}
	}
	cout << max_idx - 4000 << '\n';

	// 범위
	cout << all[n - 1] - all[0] << '\n';

	return 0;
}