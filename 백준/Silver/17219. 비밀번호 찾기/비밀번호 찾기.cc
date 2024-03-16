#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int n, m;
	unordered_map<string, string> passmap;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string domain, pass;
		cin >> domain >> pass;
		passmap[domain] = pass;
	}
	for (int i = 0; i < m; i++)
	{
		string link;
		cin >> link;
		cout << passmap[link] << '\n';
	}
	
	return 0;
}
