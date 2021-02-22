//
// Created by panrenhua on 2/22/21.
//

#ifndef LEETCODE_LEETCODE_3_H
#define LEETCODE_LEETCODE_3_H

#include "allheaders.h"
/** 3. 无重复字符的最长子串
 * */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(256, -1);
        int ans = 0;
        int left = -1;
        // left 为子字符串左边界, 如果当前字符的上一个字符在左边界以内
        // 则左边界为 m[s[i]]
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] > left) {
                left = m[s[i]];
            }
            if (i - left > ans) {
                ans = i - left;
            }
            m[s[i]] = i;
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_3_H
