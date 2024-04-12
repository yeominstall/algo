#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pos
{
	int x;
	int y;
};

int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pos> arr;
	arr.reserve(n);
	for (int i = 0; i < n; i++)
	{
		pos p;
		cin >> p.x >> p.y;
		arr.push_back(p);
	}
	sort(arr.begin(), arr.end(), [](const pos& lhs, const pos& rhs) {
		if (lhs.x == rhs.x)
			return lhs.y < rhs.y;
		return lhs.x < rhs.x;
		});

	for (int i = 0; i < n; i++)
	{
		cout << arr[i].x << ' ' << arr[i].y << '\n';
	}

	return 0;
}
