//
// Created by panrenhua on 1/22/21.
//

#ifndef LEETCODE_LEETCODE_989_H
#define LEETCODE_LEETCODE_989_H

#include "allheaders.h"
/** 989. 数组形式的整数加法
 * */
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(), A.end());
        int c = 0;
        int i = 0;

        while(i < A.size()) {
            int n = A[i] + (K % 10) + c;
            c = n / 10;
            A[i] = n % 10;
            K = K / 10;
            i++;
        }

        if (K != 0) {
            while(K) {
                int n = K % 10 + c;
                A.push_back(n % 10);
                c = n / 10;
                K = K / 10;
            }
        }
        if (c != 0) {
            A.push_back(c);
        }
        reverse(A.begin(), A.end());
        return A;
    }
};

#endif //LEETCODE_LEETCODE_989_H
