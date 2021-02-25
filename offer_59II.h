//
// Created by panrenhua on 2/25/21.
//

#ifndef LEETCODE_OFFER_59II_H
#define LEETCODE_OFFER_59II_H

#include "allheaders.h"
/** 剑指 Offer 59 - II. 队列的最大值
 * */
class MaxQueue {
public:
    queue<int> q;
    deque<int> dq;
    MaxQueue() {

    }

    int max_value() {
        if (!q.empty()) {
            return dq.front();
        }else {
            return -1;
        }
    }

    void push_back(int value) {
        q.push(value);

        while (!dq.empty() && value > dq.back()) {
            dq.pop_back();
        }
        dq.push_back(value);
    }

    int pop_front() {
        if (q.empty()) return -1;
        int front = q.front();
        q.pop();

        if (front == dq.front()) {
            dq.pop_front();
        }
        return front;
    }
};
#endif //LEETCODE_OFFER_59II_H
