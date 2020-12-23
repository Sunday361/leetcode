//
// Created by panrenhua on 2020/12/24.
//

#ifndef LEETCODE_LEETCODE_135_H
#define LEETCODE_LEETCODE_135_H

#include "allheaders.h"
/** 135. 分发糖果
 * 每个人可以获得至少一个糖果 从 1 到 n 遍历 凡是得分更高的人都至少应该比前面的人多一个
 * 然后从 n 到 1 遍历 也是同样的结果
 * */

class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        vector<int> candy(len, 1);
        for (int i = 1; i < len; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }
        for (int i = len - 1; i > 0; i--) {
            /** 如果经过前次遍历 candy[i - 1] > candy[i] 就已经满足条件了 */
            if (ratings[i - 1] > ratings[i] && candy[i - 1] <= candy[i]) {
                candy[i - 1] = candy[i] + 1;
            }
        }
        int res = 0;
        for (auto& c:candy) {
            res += c;
        }
        return res;
    }
};
#endif //LEETCODE_LEETCODE_135_H
