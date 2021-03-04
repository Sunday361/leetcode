//
// Created by panrenhua on 3/4/21.
//

#ifndef LEETCODE_LEETCODE_22_H
#define LEETCODE_LEETCODE_22_H
#include "allheaders.h"
/** 22. 括号生成
 * */
class Solution {
public:
    vector<string> ans;
    int n_;
    void dfs(int l, int r, string s) {
        if (l == r && l == n_) {
            ans.push_back(s);
            return;
        }else {
            if (l == r && l < n_) {
                dfs(l + 1, r, s + "(");
            }else if (l > r && l < n_){
                dfs(l + 1, r, s + "(");
                dfs(l, r + 1, s + ")");
            }else if (l == n_) {
                dfs(l, r + 1, s + ")");
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        n_ = n;
        dfs(0, 0, "");
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_22_H
