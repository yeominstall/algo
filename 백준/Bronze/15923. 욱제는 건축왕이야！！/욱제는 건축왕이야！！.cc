#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int n, sx, sy, x, y, nx, ny, len = 0;
	cin >> n;
	cin >> x >> y;
	sx = x; sy = y;
	for (int i = 1; i < n; i++)
	{
		cin >> nx >> ny;
		len += (abs(nx - x) + abs(ny - y));
		x = nx; y = ny;
	}
	len += (abs(sx - x) + abs(sy - y));
	cout << len << '\n';
	return 0;
}
