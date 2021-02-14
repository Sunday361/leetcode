//
// Created by panrenhua on 2/14/21.
//

#ifndef LEETCODE_LEETCODE_765_H
#define LEETCODE_LEETCODE_765_H

#include "allheaders.h"
/** 765. 情侣牵手
 * 记录每个人的位置 遍历所有组 如果不匹配根据 map 来交换
 * */
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int, int> m;
        for (int i = 0; i < row.size(); i++) {
            m[row[i]] = i;
        }
        int ans = 0;
        for (int k = 0; k < row.size()/2; k++) {
            int i = 2*k;
            if ((row[i] % 2 == 0 && row[i + 1] - row[i] == 1) || (row[i] % 2 == 1 && row[i + 1] - row[i] == -1)) {
                continue;
            }else {
                if (row[i] % 2 == 0) {
                    m[row[i + 1]] = m[row[i] + 1];
                    swap(row[m[row[i] + 1]], row[i + 1]);
                }else {
                    m[row[i + 1]] = m[row[i] - 1];
                    swap(row[m[row[i] - 1]], row[i + 1]);
                }
                ans++;
            }
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_765_H
