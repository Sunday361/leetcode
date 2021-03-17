//
// Created by panrenhua on 3/17/21.
//

#ifndef LEETCODE_LEETCODE_179_H
#define LEETCODE_LEETCODE_179_H
#include "allheaders.h"
/** 179. 最大数
 * 比较两个 字符串大小
 *  a + b < b + a
 * */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;

        for (auto& num : nums) {
            v.push_back(to_string(num));
        }

        sort(v.begin(), v.end(), [&](string& a, string& b) {
            return  a + b > b + a;
        });
        string ans = "";
        for (auto& s : v) {
            ans += s;
        }
        if (ans[0] == '0') ans = ans.substr(0, 1);
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_179_H
