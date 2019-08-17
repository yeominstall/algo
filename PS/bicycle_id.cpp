/**
 * oncoder 15. july 1
 */

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution{
public:
    int getNo8 (int N) {
        int cnt = 0;
        while (N != 0) {
            if (N % 10 == 8) {
                cnt++;
            }
            N /= 10;
        }
        return cnt;
    }

    int solution(int low, int high){
        int diff = high - low;
        int l_pos = 1, h_pos = 1, d_pos = 1, no8 = 100, tmp;
        int div = 10;
        while (high / div != 0) {
            if (low / div != 0) {
                l_pos++;
            }
            if (diff / div != 0) {
                d_pos++;
            }
            h_pos++;
            div *= 10;
        }
        if (h_pos != l_pos) {
            return 0;
        } else {
            for (int i = low; i <= high; i++) {
                tmp = getNo8 (i);
                no8 = (no8 > tmp) ? tmp : no8;
            }
        }
        return no8;
    }
};