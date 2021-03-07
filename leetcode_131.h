//
// Created by panrenhua on 3/7/21.
//

#ifndef LEETCODE_LEETCODE_131_H
#define LEETCODE_LEETCODE_131_H

#include "allheaders.h"
/** 131. 分割回文串
 * */
class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<string>> ans;
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j && s[i] == s[j]) {
            i++; j--;
        }
        if (i < j) return false;
        return true;
    }
    void dfs(string s, int k, vector<string>& v) {
        if (k == s.size()) {
            ans.push_back(v);
            return;
        }else {
            for (int i = k; i < s.size(); i++) {
                string next = s.substr(k, i - k + 1);
                if (dp[k][i] == -1) {
                    continue;
                }else if (dp[k][i] == 1 || (dp[k][i] = isPalindrome(next)) == 1) {
                    v.push_back(next);
                    dfs(s, i + 1, v);
                    v.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp.resize(n, vector<int>(n));
        vector<string> t;
        dfs(s, 0, t);
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_131_H
