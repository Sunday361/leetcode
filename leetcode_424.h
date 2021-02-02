//
// Created by panrenhua on 2/2/21.
//

#ifndef LEETCODE_LEETCODE_424_H
#define LEETCODE_LEETCODE_424_H

#include "allheaders.h"
/** 424. 替换后的最长重复字符
 * */
class Solution {
public:
    int characterReplacement(string s, int k) {
        if (k >= s.size()) return s.size();
        vector<vector<int>> dp(26, vector<int>());

        for (int i = 0; i < s.size(); i++) {
            dp[s[i] - 'A'].push_back(i);
        }
        int ans = k + 1;
        for (int i = 0; i < 26; i++) {
            if (dp[i].size() <= 1) {
                continue;
            }else {
                int u = 0, v = 0;
                while(v < dp[i].size()) {
                    while(v < dp[i].size() && v >= u && dp[i][v] - dp[i][u] - v + u <= k) {
                        ans = max(ans, k + v - u + 1);
                        v++;
                    }
                    while(v < dp[i].size() && v >= u && dp[i][v] - dp[i][u] - v + u > k) {
                        u++;
                    }
                }
            }
        }
        ans = ans < s.size() ? ans : s.size();
        return ans;
    }
    // 滑动窗口
    int _characterReplacement(string s, int k) {
        vector<int> num(26);
        int n = s.length();
        int maxn = 0;
        int left = 0, right = 0;
        while (right < n) {
            num[s[right] - 'A']++;
            maxn = max(maxn, num[s[right] - 'A']);
            if (right - left + 1 - maxn > k) { // 需要填充的字符数大于k 窗口需要左边界需要右移
                num[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return right - left;
    }
};

#endif //LEETCODE_LEETCODE_424_H
