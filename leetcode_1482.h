//
// Created by panrenhua on 5/9/21.
//

#ifndef LEETCODE_LEETCODE_1482_H
#define LEETCODE_LEETCODE_1482_H
/** 1482. 制作 m 束花所需的最少天数
 * */
#include "allheaders.h"
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < m * k) return -1;
        int lo = INT32_MAX, hi = INT32_MIN;
        for (int i = 0; i < n; i++) {
            lo = min(bloomDay[i], lo);
            hi = max(bloomDay[i], hi);
        }

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            //cout << mid << endl;
            int count = 0;
            int nums = 0;
            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) {
                    count++;
                }else {
                    count = 0;
                }

                if (count == k) {
                    count = 0;
                    nums++;
                }
            }

            if (nums >= m) {
                hi = mid;
            }else if (nums < m) {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
#endif //LEETCODE_LEETCODE_1482_H
