#ifndef CPP_LEETCODE_435_H
#define CPP_LEETCODE_435_H

/** 435. 无重叠区间
 * 求最多有多少非重叠区间
 * 贪心算法获得局部最优解
 * */
#include "allheaders.h"
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
           if (a[0] != b[0]) return a[0] < b[0];
           return a[1] < b[1];
        });
        vector<int> inter = intervals[0];
        int count = 1;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] == inter[0]) continue;
            else if (intervals[i][0] >= inter[1]) {
                inter = intervals[i];
                count++;
            }else if (intervals[i][1] < inter[1]) {
                inter = intervals[i];
            }
        }

        return intervals.size() - count;
    }
};


#endif //CPP_LEETCODE_435_H
