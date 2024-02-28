#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string subject;
	string rate;
	double point;
	double total_point = 0.0;
	double total_rate = 0.0;
	const int cnt = 20;
	unordered_map<string, double> t;
	t["A+"] = 4.5;
	t["A0"] = 4.0;
	t["B+"] = 3.5;
	t["B0"] = 3.0;
	t["C+"] = 2.5;
	t["C0"] = 2.0;
	t["D+"] = 1.5;
	t["D0"] = 1.0;
	t["F"] = 0.0;

	for (int i = 0; i < cnt; i++)
	{
		cin >> subject >> point >> rate;
		if (rate == "P") continue;
		else
		{
			total_point += point;
			total_rate += (t[rate] * point);
		}
	}
	cout.precision(8);
	cout << total_rate / total_point << '\n';
	return 0;
}