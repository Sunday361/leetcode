//
// Created by panrenhua on 3/20/21.
//

#ifndef LEETCODE_LEETCODE_386_H
#define LEETCODE_LEETCODE_386_H
#include "allheaders.h"
/** 386. 字典序排数
 * */
class Solution {
public:
    vector<int> ans;
    void preOrder(int n, int cur) {
        if (cur > n) return;
        int len = 10;
        if (cur == 1) len = 9;
        for (int i = 0; i < len && cur + i <= n; i++) {
            ans.push_back(cur + i);
            preOrder(n, (cur + i) * 10);
        }
    }
    vector<int> lexicalOrder(int n) {
        preOrder(n, 1);
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_386_H
