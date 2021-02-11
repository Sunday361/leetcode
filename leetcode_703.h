//
// Created by panrenhua on 2/11/21.
//

#ifndef LEETCODE_LEETCODE_703_H
#define LEETCODE_LEETCODE_703_H

#include "allheaders.h"
/** 703. 数据流中的第 K 大元素
 *  利用小根堆 存放K个元素
 *  c++ 优先队列是 greater 是小根堆
 * */
class KthLargest {
public:
    int k_;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for (int i = 0; i < nums.size(); i++) {
            if (pq.size() != k_) {
                pq.push(nums[i]);
            }else if (pq.size() == k_ && pq.top() < nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }

    int add(int val) {
        if (pq.size() != k_) {
            pq.push(val);
        }else if (pq.size() == k_ && pq.top() < val) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};
#endif //LEETCODE_LEETCODE_703_H
