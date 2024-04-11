#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cost
{
	int r;
	int g;
	int b;
};

int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<cost> housing;
	housing.reserve(n);

	cost paint;
	cin >> paint.r >> paint.g >> paint.b;
	housing.push_back(paint);
	for (int i = 1; i < n; i++)
	{
		cin >> paint.r >> paint.g >> paint.b;
		paint.r += min(housing[i - 1].g, housing[i - 1].b);
		paint.g += min(housing[i - 1].r, housing[i - 1].b);
		paint.b += min(housing[i - 1].r, housing[i - 1].g);
		housing.push_back(paint);
	}
	int a = min(housing[n - 1].r, housing[n - 1].g);
	cout << min(a, housing[n - 1].b) << '\n';

	return 0;
}
