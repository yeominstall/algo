#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int add(int a, const int& b)
{
	return a + b;
}

int sub(int a, const int& b)
{
	return a - b;
}

int main(void)
{
	char ip[51];
	char* c = ip;
	string numstr; int num;
	vector<int> nums;
	vector<char> ops;
	int (*operation)(int, const int&) = nullptr;
	memset(ip, 0, sizeof(ip));
	scanf("%s", ip);

	//- 단위로 묶으면 될듯..?
	while (*c != '\0')
	{
		if (*c != '+' && *c != '-')
		{
			numstr += *c;
		}
		else
		{
			num = atoi(numstr.c_str());
			nums.emplace_back(num);
			ops.emplace_back(*c);
			numstr.clear();
		}
		c++;
	}
	num = atoi(numstr.c_str());
	nums.emplace_back(num);

	int ans = nums[0];
	operation = add;
	for (int i = 0; i < ops.size(); i++)
	{
		if (ops[i] == '-')
		{
			operation = sub;
		}
		ans = operation(ans, nums[i + 1]);
	}

	printf("%d\n", ans);
	
	return 0;
}