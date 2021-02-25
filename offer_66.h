//
// Created by panrenhua on 2/25/21.
//

#ifndef LEETCODE_OFFER_66_H
#define LEETCODE_OFFER_66_H

#include "allheaders.h"
/** 剑指 Offer 66. 构建乘积数组
 * */
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> b(a.size(), 1);
        int temp = 1;
        for (int i = 0; i < a.size(); i++) {
            b[i] *= temp;
            temp *= a[i];
        }
        temp = 1;
        for (int i = a.size() - 1; i >= 0; i--) {
            b[i] *= temp;
            temp *= a[i];
        }

        return b;
    }
};
#endif //LEETCODE_OFFER_66_H
