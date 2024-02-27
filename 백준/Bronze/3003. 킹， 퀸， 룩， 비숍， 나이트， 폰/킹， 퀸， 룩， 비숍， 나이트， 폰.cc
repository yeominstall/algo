#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;
	const int correct[6] = { 1, 1, 2, 2, 2, 8 };
	for (int i = 0; i < 6; i++)
	{
		cin >> cnt;
		cout << correct[i] - cnt << " ";
	}
	cout << '\n';
	return 0;
}
