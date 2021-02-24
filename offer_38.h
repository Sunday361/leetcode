//
// Created by panrenhua on 2/24/21.
//

#ifndef LEETCODE_OFFER_38_H
#define LEETCODE_OFFER_38_H

#include "allheaders.h"
/** 剑指 Offer 38. 字符串的排列
 * */
class Solution {
public:
    vector<string> ans;
    vector<int> flag;
    string t = "";
    void dfs(string s) {
        if (t.size() == s.size()) {
            ans.push_back(t);
        }else {
            int prev = -1;
            for (int i = 0; i < s.size(); i++) {
                if (flag[i] == 0) {
                    if (prev == -1 || s[i] != prev) {
                        prev = s[i];
                        t.push_back(s[i]);
                        flag[i] = 1;
                        dfs(s);
                        flag[i] = 0;
                        t.pop_back();
                    }
                }
            }
        }
    }
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        flag.resize(s.size(), 0);
        dfs(s);
        return ans;
    }
};
#endif //LEETCODE_OFFER_38_H
