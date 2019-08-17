#include <iostream>

unsigned long meds[65] = {
2UL, 4UL, 8UL, 16UL, 32UL, 64UL, 128UL, 256UL, 512UL, 1024UL, 2048UL, 4096UL, 8192UL, 16384UL, 32768UL, 65536UL, 131072UL, 262144UL, 524288UL, 1048576UL, 2097152UL, 4194304UL, 8388608UL, 16777216UL, 33554432UL, 67108864UL, 134217728UL, 268435456UL, 536870912UL, 1073741824UL, 2147483648UL, 4294967296UL, 8589934592UL, 17179869184UL, 34359738368UL, 68719476736UL, 137438953472UL, 274877906944UL, 549755813888UL, 1099511627776UL, 2199023255552UL, 4398046511104UL, 8796093022208UL, 17592186044416UL, 35184372088832UL, 70368744177664UL, 140737488355328UL, 281474976710656UL, 562949953421312UL, 1125899906842624UL, 2251799813685248UL, 4503599627370496UL, 9007199254740992UL, 18014398509481984UL, 36028797018963968UL, 72057594037927936UL, 144115188075855872UL, 288230376151711744UL, 576460752303423488UL, 1152921504606846976UL, 2305843009213693952UL, 4611686018427387904UL, 9223372036854775808
};

int getAns (unsigned long N) {
    unsigned long median = 0;
    int flag = 0, p = 0;
    while (meds[p] < N) {
        median = meds[p++];
    }
    while (1) {
        if (median == N) return 0;
        else if (median > N) median /= 2;
        else {
            if (N == 1) return flag % 2;
            else if (N == 3) return (flag + 1) % 2;
            else {
                N = median * 2ULL - N;
                flag = (flag + 1) % 2;
                median /= 2;
                std::cout << N << " " << median << " " << flag << "\n";
            }
        }
    }
}

int main (void) {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        unsigned long K;
        std::cin >> K;
        std::cout << "#" << tc << " " << getAns(K) << "\n";
    }
    return 0;
}