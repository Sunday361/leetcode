//
// Created by panrenhua on 1/20/21.
//

#ifndef LEETCODE_LEETCODE_60_H
#define LEETCODE_LEETCODE_60_H

#include "allheaders.h"
/** 60. 排列序列
 * 根据每次模的值 找出当前剩余数组中排名第 K 的数字
 * */
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }

        --k;
        string ans;
        vector<int> valid(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            int order = k / factorial[n - i] + 1;
            for (int j = 1; j <= n; ++j) {
                order -= valid[j];
                if (!order) {
                    ans += (j + '0');
                    valid[j] = 0;
                    break;
                }
            }
            k %= factorial[n - i];
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_60_H
