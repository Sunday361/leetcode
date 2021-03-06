//
// Created by panrenhua on 3/6/21.
//

#ifndef LEETCODE_LEETCODE_155_H
#define LEETCODE_LEETCODE_155_H
#include "allheaders.h"
class MinStack {
    class MinStack {
    public:
        /** initialize your data structure here. */
        stack<int> s;
        stack<int> ms;
        MinStack() {
            ms.push(INT_MAX);
        }

        void push(int x) {
            s.push(x);
            int minNum = min(ms.top(), x);
            ms.push(minNum);
        }

        void pop() {
            s.pop();
            ms.pop();
        }

        int top() {
            return s.top();
        }

        int getMin() {
            return ms.top();
        }
    };
#endif //LEETCODE_LEETCODE_155_H
