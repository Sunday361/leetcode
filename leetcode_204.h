#ifndef CPP_LEETCODE_204_H
#define CPP_LEETCODE_204_H
/** 204. 计数质数
 * */
#include "allheaders.h"
class Solution {
public:
    int countPrimes(int n) {
        vector<int> p(n, 0);
        int count = 0;
        if (n <= 2) return 0;

        for (int i = 2; i <= n / 2; i++) {
            for (int j = 2; j * i < n; j++) {
                p[i*j] = 1;
            }
        }
        for (int i = 2; i < n; i++) {
            if (p[i] == 0) count++;
        }
        return count;
    }
};
#endif //CPP_LEETCODE_204_H
