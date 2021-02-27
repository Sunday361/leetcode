//
// Created by panrenhua on 2/27/21.
//

#ifndef LEETCODE_LEETCODE_395_H
#define LEETCODE_LEETCODE_395_H

#include "allheaders.h"
/** 395. 至少有K个重复字符的最长子串
 * */
class Solution {
public:
    int longestSubstring(string s, int left, int right, int k) {
        if (right - left + 1 < k) {
            return 0;
        }
        for (int i = left; i <= right; i++) {
            if (m[right + 1][s[i] - 'a'] - m[left][s[i] - 'a'] < k) {
                return max(longestSubstring(s, left, i - 1, k), longestSubstring(s, i + 1, right, k));
            }
        }
        return right - left + 1;
    }
    vector<vector<int>> m;
    int longestSubstring(string s, int k) {
        m.resize(s.size() + 1, vector<int>(26, 0));

        for (int i = 0; i < s.size(); i++) {
            m[i + 1] = m[i];
            m[i + 1][s[i] - 'a'] = m[i][s[i] - 'a'] + 1;
        }
        return longestSubstring(s, 0, s.size() - 1, k);
    }
};
#endif //LEETCODE_LEETCODE_395_H
