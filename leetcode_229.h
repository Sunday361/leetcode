//
// Created by panrenhua on 3/30/21.
//

#ifndef LEETCODE_LEETCODE_229_H
#define LEETCODE_LEETCODE_229_H
#include "allheaders.h"
/** 229. 求众数 II
 * moore 投票法 选取n个人, 则每个人投票可能不小于 1/(n+1)
 * */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m1 = nums[0], m2 = nums[0];
        int c1 = 0, c2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == m1) {
                c1++;
            }else if (nums[i] == m2) {
                c2++;
            }else {
                if (c1 == 0) {
                    m1 = nums[i];
                    c1 = 1;
                }else if (c2 == 0) {
                    m2 = nums[i];
                    c2 = 1;
                }else {
                    c1--;
                    c2--;
                }
            }
        }
        c1 = c2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == m1) {
                c1++;
            }
            if (nums[i] == m2) {
                c2++;
            }
        }
        vector<int> ans;
        if (c1 > nums.size() / 3) {
            ans.push_back(m1);
        }
        if (m1 != m2 && c2 > nums.size() / 3) {
            ans.push_back(m2);
        }

        return ans;
    }
};
#endif //LEETCODE_LEETCODE_229_H
