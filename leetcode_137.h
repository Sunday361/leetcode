//
// Created by panrenhua on 3/4/21.
//

#ifndef LEETCODE_LEETCODE_137_H
#define LEETCODE_LEETCODE_137_H

#include "allheaders.h"
/** 137. 只出现一次的数字 II
 * 每个数对应二进制 出现3次代表每一位都出现了3次 而出现一次代表仅出现一次
 * */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32, 0);
        int mask = 1;
        for (int i = 0; i < 32; i++) {
            for (auto& num : nums) {
                if (num & (mask << i)) {
                    bits[i]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans += ((bits[i] % 3) << i);
        }
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_137_H
