#include <iostream>
#include <cstring>

using namespace std;

char str[1000];

int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		cin >> str;
		cout << str[0] << str[strlen(str) - 1] << '\n';
	}

	return 0;
}