#ifndef CPP_LEETCODE_376_H
#define CPP_LEETCODE_376_H

/** 376. 摆动序列
 * */
#include "allheaders.h"
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> s;
        int flag = 1;
        s.push_back(nums[0]); // 可以用一个pre代替
        int i = 1;
        for (i; i < nums.size(); i++) {
            if (nums[i] > s[0]) {
                s.push_back(nums[i]);
                flag = 1;
            } else if (nums[i] < s[0]) {
                s.push_back(nums[i]);
                flag = 0;
            }
        }
        for (i; i < nums.size(); i++) {
            if (nums[i] == s.back()) continue;
            if (flag == 1 && nums[i] < s.back()) {
                s.push_back(nums[i]);
                flag = 0;
            }else if (flag == 0 && nums[i] > s.back()) {
                s.push_back(nums[i]);
                flag = 1;
            }else if ((flag == 0 && nums[i] < s.back()) || (flag == 1 && nums[i] > s.back())){
                s.back() = nums[i];
            }
        }

        return s.size();
    }
};


#endif //CPP_LEETCODE_376_H
