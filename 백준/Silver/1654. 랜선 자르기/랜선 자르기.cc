#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int k, n;
	uint32_t length;
	vector<uint32_t> cables;
	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		cin >> length;
		cables.emplace_back(length);
	}
	sort(cables.rbegin(), cables.rend());

	uint32_t base[3];	// 케이블 기준 길이 history (최소 / 중위값 / 최대)
	int cnt;		// base 기준 만들 수 있는 케이블의 수
	base[0] = cables[0];
	do
	{
		cnt = 0;
		for (auto& i : cables)
			cnt += (i / base[0]);

		if (cnt >= n) break;

		base[2] = base[0];
		base[0] /= 2;
	} while (base[0] > 0);

	// 최적 길이 구하기 (base[0] <= x < base[2])
	while (base[0] + 1 < base[2])
	{
		cnt = 0;
		base[1] = (base[0] + base[2]) / 2;
		for (auto& i : cables)
			cnt += (i / base[1]);

		if (cnt >= n)
			base[0] = base[1];
		else
			base[2] = base[1];
	}

	cout << base[0] << '\n';

	return 0;
}