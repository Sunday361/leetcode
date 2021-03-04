//
// Created by panrenhua on 3/4/21.
//

#ifndef LEETCODE_LEETCODE_89_H
#define LEETCODE_LEETCODE_89_H
#include "allheaders.h"
/** 89. 格雷编码
 * 递归 对于n位数字 n-1 相当与在最高位为1 再递推
 * 比如 000 001 011 010 -> 110 111 101 100
 * */
class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return {0};
        if (n == 1) return {0, 1};
        if (n > 2) {
            auto ans = grayCode(n - 1);
            auto copy = ans;
            reverse(copy.begin(), copy.end());

            for (auto& c : copy) {
                c += pow(2, n - 1);
            }

            ans.insert(ans.end(), copy.begin(), copy.end());

            return ans;
        }
    }
};
#endif //LEETCODE_LEETCODE_89_H
