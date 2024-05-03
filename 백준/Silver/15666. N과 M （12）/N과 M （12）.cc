#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, m, input;
vector<unsigned int> comb;
set<unsigned int> nums;

void print(void)
{
	for (auto it = comb.begin(); it != comb.end(); ++it)
		cout << *it << ' ';
	cout << '\n';
}

void bfs(set<unsigned int>::iterator iter)
{
	if (comb.size() == m)
	{
		print();
		return;
	}

	for (auto it = iter; it != nums.end(); ++it)
	{
		comb.push_back(*it);
		bfs(it);
		comb.pop_back();
	}
}

int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> input;
		nums.insert(input);
	}

	bfs(nums.begin());

	return 0;
}