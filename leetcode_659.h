#ifndef LEETCODE_LEETCODE_659_H
#define LEETCODE_LEETCODE_659_H

#include "allheaders.h"
/* 659. 分割数组为连续子序列
 * 1. 最大堆 用hash表保存数字出现的次数
 *
 * 2. 遍历数组 考虑将当前数字插入到已有数组 == 贪心算法
 * 若要新建数组则必须要满足 nums[i] + 1, nums[i] + 2 仍存在
 *  * class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>,greater<int>>> mp;
        for (auto& x : nums) {
            if (mp.find(x) == mp.end()) {
                mp[x] = priority_queue<int, vector<int>,greater<int>>();
            }
            if (mp.find(x - 1) != mp.end()) {
                int prevLength = mp[x - 1].top();
                mp[x - 1].pop();
                if (mp[x - 1].empty()) {
                    mp.erase(x - 1);
                }
                mp[x].push(prevLength + 1);
            } else {
                mp[x].push(1);
            }
        }
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            priority_queue<int, vector<int>,greater<int>> queue = it->second;
            if (queue.top() < 3) {
                return false;
            }
        return true;
    }
};
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