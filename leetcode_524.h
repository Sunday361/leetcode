//
// Created by panrenhua on 2/5/21.
//

#ifndef LEETCODE_LEETCODE_524_H
#define LEETCODE_LEETCODE_524_H

#include "allheaders.h"
/** 524. 通过删除字母匹配到字典里最长单词
 * */
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [&](string& a, string& b){
            if (a.size() != b.size()) return a.size() > b.size();
            else {
                return a < b;
            }
        });

        for (auto& str : d) {
            int p1 = 0, p2 = 0;
            while (p1 < s.size() && p2 < str.size()) {
                if (s[p1] == str[p2]) {
                    p1++; p2++;
                }else {
                    p1++;
                }
            }
            if (p2 == str.size()) return str;
        }
        return "";
    }
};
#endif //LEETCODE_LEETCODE_524_H
