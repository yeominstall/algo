#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	string n, answer;
	cin >> n;
	sort(n.rbegin(), n.rend());

	int sum = 0;
	for (auto& c : n)
		sum += (c - '0');

	int len = n.length();
	if (n[len - 1] == '0' && sum % 3 == 0)
		cout << n << '\n';
	else
		cout << "-1\n";

	return 0;
}