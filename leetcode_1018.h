//
// Created by panrenhua on 1/14/21.
//

#ifndef LEETCODE_LEETCODE_1018_H
#define LEETCODE_LEETCODE_1018_H

#include "allheaders.h"
/** 1018. 可被 5 整除的二进制前缀
 * */
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int len = A.size();
        vector<int> v(len, 0);
        vector<bool> ans(len, true);
        v[0] = 1;
        for (int i = 1; i < len; i++) {
            v[i] = (v[i - 1] * 2) % 5;
        }
        int pre = 0;
        for (int i = 0; i < len; i++) {
            pre = (pre + (A[i] == 0 ? 0 : v[len - 1 - i])) % 5;
            if (pre != 0) ans[i] = false;
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_1018_H
