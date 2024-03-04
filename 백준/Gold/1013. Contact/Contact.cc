#include <iostream>
#include <string>

using namespace std;

// 100+1+ 패턴 확인
bool ozzpop(string& str, string::iterator& iter)
{
	// 0
	if (++iter == str.end() || *iter != '0')
		return false;
	// 0+
	if (++iter != str.end() && *iter == '0')
		while (iter != str.end() && *iter == '0')
			iter++;
	else
		return false;
	// 1+
	if (iter != str.end() && *iter == '1')
		while (iter != str.end() && *iter == '1')
			iter++;
	else
		return false;

	return true;
}

int main(void)
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int t;
	string s;
	cin >> t;
	// (100+1+ | 01)+
	for (int i = 0; i < t; i++)
	{
		s.clear();
		cin >> s;
		// 0으로 시작할 경우 - 다음이 1이면 패스
		bool result = true;
		for (auto it = s.begin(); it != s.end() && result;)
		{
			// 01 인 경우
			if (*it == '0')
			{
				if (it + 1 != s.end() && *(it + 1) == '1')
					it += 2;
				else
					result = false;
			}
			else
			{
				result = ozzpop(s, it);
				if (result)
				{
					if (it != s.end() && *it == '0' && it + 1 != s.end() && *(it + 1) == '0')	// 다음이 00인지
					{
						if (*(it - 2) == '1')	// 직전이 11인지
							--it;
						else
							result = false;
					}
				}
			}
		}
		if (result)
			cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}