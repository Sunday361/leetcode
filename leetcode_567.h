//
// Created by panrenhua on 2/10/21.
//

#ifndef LEETCODE_LEETCODE_567_H
#define LEETCODE_LEETCODE_567_H

#include "allheaders.h"
/** 567. 字符串的排列
 * */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0, right = 0;
        map<char, int> m1;
        map<char, int> m2;
        for (auto& c : s1) {
            m1[c]++;
        }
        while (right < s2.size()) {
            if (m1.find(s2[right]) != m1.end()) {
                m2[s2[right]]++;
                while (m2[s2[right]] > m1[s2[right]] && left <= right) {
                    m2[s2[left]]--;
                    left++;
                }
                right++;
                auto it = m1.begin();
                for (; it != m1.end(); it++) {
                    if (it->second != m2[it->first])
                        break;
                }
                if (it == m1.end()) return true;
            }else {
                right++;
                m2.clear();
                left = right;
            }
        }
        return false;
    }
};
#endif //LEETCODE_LEETCODE_567_H
