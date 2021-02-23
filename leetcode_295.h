//
// Created by panrenhua on 2/23/21.
//

#ifndef LEETCODE_LEETCODE_295_H
#define LEETCODE_LEETCODE_295_H

#include "allheaders.h"
/** 295. 数据流的中位数
 * */
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> max_heap;
    priority_queue<int, vector<int>, less<int>> min_heap;
    MedianFinder() {

    }

    void addNum(int num) {
        if (max_heap.size() == min_heap.size()) {
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();
        }else {
            min_heap.push(num);
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian() {
        if (max_heap.size() == min_heap.size()) return (max_heap.top() + min_heap.top()) / 2;
        else return min_heap.top();
    }
};

#endif //LEETCODE_LEETCODE_295_H
