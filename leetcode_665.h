//
// Created by panrenhua on 2/7/21.
//

#ifndef LEETCODE_LEETCODE_665_H
#define LEETCODE_LEETCODE_665_H

#include "allheaders.h"
/** 665. 非递减数列
 * */
class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        int n = nums.size(), cnt = 0;
        for (int i = 0; i < n - 1; ++i) {
            int x = nums[i], y = nums[i + 1];
            if (x > y) {
                cnt++;
                if (cnt > 1) {
                    return false;
                }
                if (i > 0 && y < nums[i - 1]) {
                    nums[i + 1] = x;
                }
            }
        }
        return true;
    }
};

#endif //LEETCODE_LEETCODE_665_H
