//
// Created by panrenhua on 4/26/21.
//

#ifndef LEETCODE_LEETCODE_1011_H
#define LEETCODE_LEETCODE_1011_H
#include "allheaders.h"
/** 1011. 在 D 天内送达包裹的能力
 * */
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int n = weights.size();
        int lo = 0, hi = 0;
        for (int i = 0; i < n; i++) {
            hi += weights[i];
            lo = max(lo, weights[i]);
        }

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int cnt = 1;
            int temp = 0;
            for (int i = 0; i < n; i++) {
                temp += weights[i];
                if (temp > mid) {
                    cnt++;
                    temp = weights[i];
                }
            }

            if (cnt > D) {
                lo = mid + 1;
            }else{
                hi = mid;
            }
        }

        return lo;
    }
};
#endif //LEETCODE_LEETCODE_1011_H
