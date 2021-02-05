//
// Created by panrenhua on 2/5/21.
//

#ifndef LEETCODE_LEETCODE_1208_H
#define LEETCODE_LEETCODE_1208_H

#include "allheaders.h"
/** 1208. 尽可能使字符串相等
 * */
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0, right = 0;
        int cost = 0;
        int ans = 0;
        while (right < t.size()) {
            cost += abs(s[right] - t[right]);
            while (left <= right && cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_1208_H
