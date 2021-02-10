//
// Created by panrenhua on 2/10/21.
//

#ifndef LEETCODE_LEETCODE_923_H
#define LEETCODE_LEETCODE_923_H

#include "allheaders.h"
/** 923. 三数之和的多种可能
 * */
class Solution {
public:
    const int N = 1e9 + 7;
    int threeSumMulti(vector<int>& arr, int target) {
        vector<int> m(101, 0);
        long long ans = 0;
        for (auto& a : arr) {
            m[a]++;
        }
        for (int i = 0; i < m.size(); i++) {
            if (m[i] == 0) continue;
            for (int j = i; j < m.size(); j++) {
                if (m[j] == 0) continue;
                int k = target - i - j;
                if (k < 0 || k > 100 || m[k] == 0 || k < j) {
                    continue;
                }
                int a = m[i], b, c, d = 1;
                if (i == j && j == k) {
                    b = a - 1;
                    c = b - 1;
                    d = 6;
                }else if (i == j && j != k) {
                    b = a - 1;
                    c = m[k];
                    d = 2;
                }else if (i != j && j == k) {
                    b = m[j];
                    c = m[j] - 1;
                    d = 2;
                }else {
                    b = m[j];
                    c = m[k];
                }
                if (a > 0 && b > 0 && c > 0) {
                    ans += (long long)a * b * c / d;
                }
            }
        }
        return ans % N;
    }
};
#endif //LEETCODE_LEETCODE_923_H
