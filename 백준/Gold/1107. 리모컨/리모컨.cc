#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool broken[10];

int get_digit(int n)
{
	if (n == 0) return 1;

	int cnt = 0;
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return cnt;
}

bool is_ok(int n)
{
	if (n < 0)
		return false;
	if (n == 0)
		return !broken[0];

	while (n != 0)
	{
		if (broken[n % 10]) 
			return false;
		n /= 10;
	}
	return true;
}

int main(void)
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		broken[tmp] = true;
	}

	// 가장 가까운 채널로 옮기기 vs +- 하기
	int digit = get_digit(n);
	uint32_t min_cnt = abs(n - 100);

	do
	{
		if (n == 100)
			break;
		if (m == 10)
			break;
		if (n == 0)
		{
			for (int i = 0; i < 10; i++)
			{
				if (!broken[i])
				{
					min_cnt = i + 1;
					break;
				}
			}
		}
		else if (is_ok(n))
		{
			if (digit < min_cnt)
				min_cnt = digit;
		}
		else
		{
			for (int i = 1; i < min_cnt; i++)
			{
				if (is_ok(n - i))
				{
					int d = get_digit(n - i);
					if (d + i < min_cnt)
						min_cnt = d + i;
					break;
				}
				if (is_ok(n + i))
				{
					int d = get_digit(n + i);
					if (d + i < min_cnt)
						min_cnt = d + i;
					break;
				}
			}
		}
	} while (0);

	cout << min_cnt << '\n';

	return 0;
}