//
// Created by panrenhua on 2020/12/18.
//

#ifndef LEETCODE_LEETCODE_389_H
#define LEETCODE_LEETCODE_389_H

/** 389. 找不同
 * */
#include "allheaders.h"

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> dp(26, 0);
        for (int i = 0; i < s.size(); i++) {
            dp[s[i] - 'a']++;
        }

        for (int i = 0; i < t.size(); i++) {
            dp[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (dp[i] == -1) return 'a' + i;
        }
        return 'a';
    }
};


#endif //LEETCODE_LEETCODE_389_H
