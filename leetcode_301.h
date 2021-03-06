//
// Created by panrenhua on 2020/11/25.
//

#ifndef CPP_LEETCODE_301_H
#define CPP_LEETCODE_301_H
#include "allheaders.h"
/** 301. 删除无效的括号
 * void dfs(string& s, string now, int k, int l, int r)
 * l:左括号 r:右括号 k:当前位置
 * */
class Solution {
public:
    vector<string> ans;
    void dfs(string& s, string now, int k, int l, int r) {
        if (k >= s.size()) {
            if (l == r) { // 当 l == r 时 满足条件
                if (ans.size() == 0) {
                    ans.push_back(now);
                }else {
                    if (now.size() > ans.back().size()) { // 删除长度小于now的结果
                        ans.clear();
                        ans.push_back(now);
                    }else if (now.size() == ans.back().size()) {
                        ans.push_back(now);
                    }
                }
            }
            return;
        }
        if (r > l) { // 剪枝
            return;
        }else {
            while (k < s.size() && s[k] != '(' && s[k] != ')') {
                now += s[k];
                k++;
            }
            if (k < s.size() && s[k] == '(') {
                dfs(s, now + s[k], k + 1, l + 1, r);
                if (!now.empty() && s[k] == now.back())
                    return;
            }else if (k < s.size() && s[k] == ')'){
                dfs(s, now + s[k], k + 1, l, r + 1);
                if (!now.empty() && s[k] == now.back())
                    return;
            }
            dfs(s, now, k + 1, l, r);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        dfs(s, "", 0, 0, 0);
        return ans;
    }
};
#endif //CPP_LEETCODE_301_H
