//
// Created by panrenhua on 1/26/21.
//

#ifndef LEETCODE_LEETCODE_1128_H
#define LEETCODE_LEETCODE_1128_H
#include "allheaders.h"
/** 1128. 等价多米诺骨牌对的数量
 * */
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<vector<int>> m(10, vector<int>(10, 0));

        for (auto& d : dominoes) {
            if (d[0] != d[1]) {
                m[d[0]][d[1]]++;
            }
            m[d[1]][d[0]]++;
        }
        int ans = 0;
        for (int i = 1; i < 10; i++) {
            for (int j = i; j < 10; j++) {
                ans += (m[i][j] - 1) * m[i][j] / 2;
            }
        }
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_1128_H
