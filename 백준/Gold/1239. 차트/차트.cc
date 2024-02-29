#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    // 원의 중심을 지나는 선을 최대로 하려면 두 값의 차가 50이 되어야 함
    // 10 50 40 보다 10 40 50 으로 배치해야 한다.
    // 값 하나가 선이 되기 위한 값이 있는지를 찾기? 큰 수부터 배치해야 할 것 같기도
    // 한 원소의 값이 51 이상이면 선의 갯수는 0
    int n, max = -1;
    int arr[8];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    if (arr[0] > 50)
        cout << "0\n";
    else
    {
        // 순열로 배치해서 값 더하기
        int max_cnt = 0;
        do
        {
            int cnt = 0;
            for (int i = 0; i < n; i++)     // 시작점
            {
                int sum = 0;
                for (int j = i; sum < 50; j++)
                {
                    sum += (arr[j % n]);
                    if (sum == 50) cnt++;
                }
            }
            if (max_cnt < cnt) max_cnt = cnt;
        } while (next_permutation(arr, arr + n));

        cout << max_cnt / 2 << '\n';
    }

    return 0;
}