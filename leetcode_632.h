#ifndef CPP_LEETCODE_632_H
#define CPP_LEETCODE_632_H

#include "allheaders.h"

/** 632. 最小区间
 *
 * 用一个堆保存所有的值 最大值 - 最小值 = 当前区间的长度
 * 每次移动最小的那个值 使区间尽可能缩小
 * */
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> res(2);
        vector<int> index(nums.size(), 0);
        set<pair<int, int>> heap;
        for (int i = 0; i < nums.size(); i++) {
            heap.insert(make_pair(nums[i][0], i));
        }
        auto be = heap.begin();
        auto end = heap.rbegin();
        res[0] = be->first;
        res[1] = end->first;

        while (be->first != nums[be->second].back()) {
            int t = be->second;
            heap.erase(be);
            heap.insert(make_pair(nums[t][++index[t]], t));
            be = heap.begin();
            end = heap.rbegin();
            if ((res[1] - res[0]) > (end->first - be->first)) {
                res[1] = end->first;
                res[0] = be->first;
            }
        }
        return res;
    }
};

#endif //CPP_LEETCODE_632_H
