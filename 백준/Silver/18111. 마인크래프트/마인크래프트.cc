#include <iostream>
#include <climits>

using namespace std;
int16_t land[500][500];

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m, b;
    cin >> n >> m >> b;
    int sum = 0, avg;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> land[i][j];
            sum += land[i][j];
        }
    avg = sum / (n * m);

    // 평균 구해서 ceiling 또는 내림
    // 깎는 게 더 오래 걸리니까, 블록 한도 내에서 높이 높여가면서 시간 계산
    int min_time = INT_MAX, max_height = -1;
    int block = 0;
    while (block <= b)
    {
        int time = 0;
        block = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int turn = land[i][j] - avg;
                if (turn < 0)       // 땅을 높임
                    time += (-turn);
                else if (turn > 0)  // 땅을 깎음
                    time += (turn * 2);
                
                block -= turn;
            }
        }
        if (b < block)
            break;
        else
        {
            if (time <= min_time)
            {
                min_time = time;
                max_height = max(max_height, avg);
            }
            avg++;
        }
    }
    cout << min_time << " " << max_height;

    return 0;
}