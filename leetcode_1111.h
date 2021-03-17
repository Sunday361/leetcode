//
// Created by panrenhua on 3/17/21.
//

#ifndef LEETCODE_LEETCODE_1111_H
#define LEETCODE_LEETCODE_1111_H

#include "allheaders.h"
/** 1111. 有效括号的嵌套深度
 * 设置两个栈, 栈的大小即是嵌套的深度
 * */
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.size());
        stack<char> d1, d2;
        for (int i = 0; i < seq.size(); i++) {
            if (seq[i] == '(') { //
                if (d1.size() > d2.size()) {
                    d2.push(seq[i]);
                    ans[i] = 1;
                }else {
                    d1.push(seq[i]);
                    ans[i] = 0;
                }
            }else {
                if (d1.size() > d2.size()) {
                    d1.pop();
                    ans[i] = 0;
                }else {
                    d2.pop();
                    ans[i] = 1;
                }
            }
        }
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_1111_H
