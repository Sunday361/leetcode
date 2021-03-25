//
// Created by panrenhua on 3/25/21.
//

#ifndef LEETCODE_LEETCODE_17_14_H
#define LEETCODE_LEETCODE_17_14_H
#include "allheaders.h"
/** 面试题 17.14. 最小K个数
 * */
class Solution {
public:
    void smallestK(vector<int>& arr, int i, int j, int k) {
        if (k == 0) return;
        int lo = i, hi = j;
        int pos = arr[i];
        while (lo < hi) {
            while (lo < hi && arr[hi] >= pos) {
                hi--;
            }
            swap(arr[hi], arr[lo]);
            while (lo < hi && arr[lo] <= pos) {
                lo++;
            }
            swap(arr[lo], arr[hi]);
        }
        if (lo - i + 1 < k) {
            smallestK(arr, lo + 1, j, k - (lo - i + 1));
        }else if (lo - i + 1 > k){
            smallestK(arr, i, lo, k);
        }else {
            return;
        }
    }
    vector<int> smallestK(vector<int>& arr, int k) {
        smallestK(arr, 0, arr.size() - 1, k);
        if (k != 0)
            return vector<int>(arr.begin(), arr.begin() + k);
        else
            return {};
    }
};

#endif //LEETCODE_LEETCODE_17_14_H
