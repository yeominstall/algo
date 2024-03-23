#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	unordered_map<string, bool> names;
	int n, m;
	string ip;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> ip;
		names[ip] = true;
	}
	set<string> dup;
	for (int i = 0; i < m; i++)
	{
		cin >> ip;
		if (names[ip])
			dup.emplace(ip);
	}
	cout << dup.size() << '\n';
	for (auto& n : dup)
		cout << n << '\n';

	return 0;
}