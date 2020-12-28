//
// Created by panrenhua on 12/28/20.
//

#ifndef LEETCODE_LEETCODE_260_H
#define LEETCODE_LEETCODE_260_H

#include "allheaders.h"
/** 260. 只出现一次的数字 III
 *
 * 将所有值全部异或 得到 ans, 由于这两个数只出现了一次, 所以异或值 ans 必不为 0 , 取 bit = ans & (-ans) 得到最低为 1
 * 再次遍历数组 将num 与 bit 相与, 为0 说明该位为 0, 反之则为 1
 * 将其分为两组 再异或 求得最后这两个数字
 * */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        vector<int> result(2, 0);
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] & ans) == 1) {
                result[0] ^= nums[i];
            }else {
                result[1] ^= nums[i];
            }
        }
        return result;
    }
};
#endif //LEETCODE_LEETCODE_260_H
