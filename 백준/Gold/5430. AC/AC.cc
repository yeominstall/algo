#include <iostream>

using namespace std;

char func[100001];
char numstr[400002]; // 100000 * 4 + 1
unsigned short nums[100000];

// 함수 문자열을 줄인다. R끼리 상쇄. RRD-> D, RDDRRR-> RDDR
void shortener(void)
{
	int r_seq = 0;
	char* save, * p;
	save = p = func;

	while (*p != '\0')
	{
		if (*p == 'R')
			r_seq++;
		else
		{
			if (r_seq > 0)
			{
				if (r_seq % 2 == 1)
				{
					*save = 'R';
					save++;
				}
				r_seq = 0;
			}
			*save = *p;
			save++;
		}
		p++;
	}
	// 문자열 끝부분에 남은 R 있으면 처리
	if (r_seq % 2 == 1)
	{
		*save = 'R';
		save++;
	}
	*save = '\0';
}

// 입력받은 숫자 문자열을 short 배열로
void parsenums(void)
{
	char* n = numstr + 1;	// 맨앞 [ 제거
	unsigned short* p = nums;
	int tmp = 0;
	while (*n != '\0')
	{
		if (*n >= '0' && *n <= '9')
		{
			tmp *= 10;
			tmp += (*n - '0');
		}
		else
		{
			*p = tmp;
			tmp = 0;
			p++;
		}
		n++;
	}
}

// 함수 적용
bool run(unsigned int& begin, unsigned int& end)
{
	int op = 1;
	char* pc = func;
	while (*pc != '\0')
	{
		if (*pc == 'D')
		{
			if (begin == end)
				return false;
			begin += op;
		}
		else
		{
			int tmp = begin;
			begin = end;
			end = tmp;
			op *= (-1);
		}
		pc++;
	}
	return true;
}

void printnum(unsigned int& begin, unsigned int& end)
{
	int i = 0;
	if (begin == end)
	{
		cout << "[]\n";
		return;
	}
	cout << '[';
	if (begin < end)
	{
		for (i = begin; i < (end - 1); i++)
			cout << nums[i] << ',';
	}
	else if (begin > end)
	{
		for (i = begin - 1; i >= (end + 1); i--)
			cout << nums[i] << ',';
	}
	cout << nums[i] << "]\n";
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		cin >> func;
		int num_count;
		cin >> num_count;
		cin >> numstr;
		parsenums();
		shortener();
		unsigned int b = 0, e = num_count;
		if (!run(b, e))
			cout << "error\n";
		else
			printnum(b, e);
	}

	return 0;
}