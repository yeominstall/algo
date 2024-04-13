#include <iostream>
#include <vector>

using namespace std;

int lcs(const string& s1, const string& s2)
{
	vector<vector<int>> lcs_table;
	lcs_table.resize(s1.size() + 1);
	lcs_table[0].resize(s2.size() + 1);
	for (int i = 0; i < s2.size() + 1; ++i)
		lcs_table[0][i] = 0;

	for (int i = 0; i < s1.size(); ++i)
	{
		lcs_table[i + 1].resize(s2.size() + 1, 0);
		for (int j = 0; j < s2.size(); ++j)
		{
			if (s1[i] != s2[j])
				lcs_table[i + 1][j + 1] = max(lcs_table[i + 1][j], lcs_table[i][j + 1]);
			else
				lcs_table[i + 1][j + 1] = lcs_table[i][j] + 1;
		}
	}

	int maxval = -1;
	for (int i = 1; i <= s1.size(); ++i)
		for (int j = 1; j <= s2.size(); ++j)
			maxval = max(maxval, lcs_table[i][j]);

	return maxval;
}

int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	string str1, str2;
	cin >> str1 >> str2;
	int ret = lcs(str1, str2);

	cout << ret << '\n';

	return 0;
}
