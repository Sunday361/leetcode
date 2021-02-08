//
// Created by panrenhua on 2/8/21.
//

#ifndef LEETCODE_LEETCODE_978_H
#define LEETCODE_LEETCODE_978_H

#include "allheaders.h"
/** 978. 最长湍流子数组
 * up 和 down 两个变量
 * */
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int len = A.size();
        int up = 1, down = 1;
        int ans = 1;
        for (int i = 1; i < len; i++) {
            if (A[i] > A[i - 1]) { up = down + 1; down = 1; }
            else if (A[i] < A[i - 1]) { down = up + 1; up = 1; }
            else { up = down = 1; }
            ans = max(ans, max(up, down));
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_978_H
