//
// Created by panrenhua on 2/6/21.
//

#ifndef LEETCODE_LEETCODE_1423_H
#define LEETCODE_LEETCODE_1423_H

#include "allheaders.h"
/** 1423. 可获得的最大点数
 * */
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        int ans;
        int s = 0;
        for (int i = 0; i < n - k; i++) {
            sum += cardPoints[i];
        }
        s = sum;
        ans = sum;
        for (int i = n - k; i < n; i++) {
            sum += (cardPoints[i] - cardPoints[i - n + k]);
            ans = min(sum, ans);
            s += cardPoints[i];
        }
        return s - ans;
    }
};
#endif //LEETCODE_LEETCODE_1423_H
