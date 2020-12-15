#ifndef CPP_LEETCODE_1081_H
#define CPP_LEETCODE_1081_H
#include "allheaders.h"

/** 1081. 不同字符的最小子序列
 *  316. 去除重复字母
 *  凡是涉及最小字典序，最大字典序，都可以用单调栈来解决问题
 * */
class Solution {
public:
    string smallestSubsequence(string s) {
        string res = "";
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]] = i;
        }
        set<char> resSet;
        for (int i = 0; i < s.size(); i++) {
            if (resSet.find(s[i]) == resSet.end()) {
                resSet.insert(s[i]);
                while(res.size() != 0 && s[i] < res.back() && m[res.back()] > i) {
                    resSet.erase(resSet.find(res.back()));
                    res.pop_back();
                }
                res.push_back(s[i]);
            }
        }
        return res;
    }
};


#endif //CPP_LEETCODE_1081_H
