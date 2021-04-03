//
// Created by panrenhua on 4/1/21.
//

#ifndef LEETCODE_LEETCODE_679_H
#define LEETCODE_LEETCODE_679_H
#include "allheaders.h"
/** 679. 24 点游戏
 * */
class Solution {
public:
    double helper(double a, double b, int opt) {
        switch (opt) {
            case 1:
                return a + b;
            case 2:
                return a - b;
            case 3:
                return a * b;
            case 0:
                return a / b;
        }
        return 0;
    }

    bool judgePoint24(vector<int>& nums, vector<int>& f, double ans) {
        int flag = 0;
        for (int i = 0; i < 4; i++) {
            if (f[i] != 1) {
                for (int j = 0; j < 4; j++) {
                    double next;
                    if (j == 0 && (nums[i] == 0 || ans == 0)) {
                        if (nums[i] != 0) {
                            next = helper(ans, nums[i], j);
                            f[i] = 1;
                            if (judgePoint24(nums, f, next)) {
                                return true;
                            }
                        }else if (ans != 0){
                            next = helper(nums[i], ans, j);
                            f[i] = 1;
                            if (judgePoint24(nums, f, next)) {
                                return true;
                            }
                        }
                        f[i] = 0;
                        continue;
                    }
                    next = helper(ans, nums[i], j);
                    f[i] = 1;
                    if (judgePoint24(nums, f, next)) {
                        return true;
                    }
                    next = helper(nums[i], ans, j);
                    if (judgePoint24(nums, f, next)) {
                        return true;
                    }
                    f[i] = 0;
                }
                flag = 1;
            }
        }
        if (!flag && abs(ans - 24)< 1e-6) {
            return true;
        }
        return false;
    }
    bool judgePoint24(vector<int>& nums) {
        vector<int> f(4, 0);
        for (int i = 0; i < 4; i++) {
            f[i] = 1;
            if (judgePoint24(nums, f, nums[i])) {
                return true;
            }
            f[i] = 0;
        }
        return false;
    }
};
#endif //LEETCODE_LEETCODE_679_H
