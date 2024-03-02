#include <iostream>
#include <vector>

using namespace std;

// return 
int& filler(const int& digit, vector<int64_t>& former, vector<int64_t>& current, int& counter)
{
	current.clear();
	int64_t multiply = 1;
	for (int m = 1; m < digit; m++) multiply *= 10;
	for (int i = digit - 1; i < 10; i++)
	{
		for (int j = 0; j < former.size(); j++)
		{
			int first = former[j] / (multiply / 10);
			if (first >= i) break;
			current.emplace_back(former[j] + (multiply * i));
		}
	}
	counter += current.size();
	return counter;
}

//test
void printthis(const vector<int64_t>& arr)
{
	for (auto& i : arr)
		cout << i << ' ';
	cout << "====================================";
}

int main(void)
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int n;
	cin >> n;
	// 마지막 번째 감소하는 수: 9876543210 > INT_MAX(2147483648)
	// 각 자리수에서 몇 개의 감소하는 수가 나올 수 있는지
	// 1 : 0 ~ 9 (10)
	// 2 : 10, 21, 20, 32, 31, 30, ... , 98, 97, ... 90 (45) = 1 + 2 + 3 + ... + 9
	// 3 : 210, 310, 321, 320, ..., 987
	// 4 : 3210 
	vector<int64_t> arr1{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int64_t> arr2;
	int64_t result = -1;

	if (n < 10)
		result = n;
	else
	{
		vector<int64_t>& former = arr1;
		vector<int64_t>& current = arr2;
		int counter = arr1.size() - 1;
		for (int i = 2; i <= 10; i++)
		{
			counter = filler(i, former, current, counter);
			if (counter >= n)
			{
				// vector.size() - (counter - n) == 현재 벡터에서의 인덱스
				int index = current.size() - (counter + 1 - n);
				result = current[index];
				//printthis(current);
				break;
			}
			else
				former.swap(current);
		}
	}
	cout << result << '\n';

	return 0;
}