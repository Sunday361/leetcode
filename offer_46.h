//
// Created by panrenhua on 2/23/21.
//

#ifndef LEETCODE_OFFER_46_H
#define LEETCODE_OFFER_46_H
/** 剑指 Offer 46. 把数字翻译成字符串
 * */
#include "allheaders.h"
class Solution {
public:
    int ans = 0;

    void dfs(int k, string& s) {
        if (k == s.size()) {
            ans++; return;
        }
        else {
            if (k == s.size() - 1) {
                dfs(k + 1, s);
            }else {
                dfs(k + 1, s);
                if (s[k] != '0' && (s[k] - '0') * 10 + s[k + 1] - '0' < 26) {
                    dfs(k + 2, s);
                }
            }
        }
    }
    int translateNum(int num) {
        string s = to_string(num);
        dfs(0, s);
        return ans;
    }
};
#endif //LEETCODE_OFFER_46_H
