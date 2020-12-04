#ifndef LEETCODE_LEETCODE_659_H
#define LEETCODE_LEETCODE_659_H

#include "allheaders.h"
/* 659. 分割数组为连续子序列
 * 1. 最大堆 用hash表保存数字出现的次数
 *
 * 2. 遍历数组 考虑将当前数字插入到已有数组 == 贪心算法
 * 若要新建数组则必须要满足 nums[i] + 1, nums[i] + 2 仍存在
 *  *
 * */
class Solution{
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> m;
        unordered_map<int, int> lists;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (m[nums[i]] == 0) continue;

            m[nums[i]]--;
            if (lists[nums[i] - 1] != 0) {
                lists[nums[i] - 1]--;
                lists[nums[i]]++;
            }else {
                if (m[nums[i] + 1] != 0 && m[nums[i] + 2] != 0) {
                    lists[nums[i] + 2]++;
                    m[nums[i] + 1]--;
                    m[nums[i] + 2]--;
                }else {
                    return false;
                }
            }
        }
        return true;
    }
};

#endif