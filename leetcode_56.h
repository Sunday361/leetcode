//
// Created by panrenhua on 1/11/21.
//

#ifndef LEETCODE_LEETCODE_56_H
#define LEETCODE_LEETCODE_56_H

#include "allheaders.h"
/** 56. 合并区间
 * */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({ L, R });
            }
            else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};
#endif //LEETCODE_LEETCODE_56_H
