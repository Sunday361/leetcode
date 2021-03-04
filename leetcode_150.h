//
// Created by panrenhua on 3/4/21.
//

#ifndef LEETCODE_LEETCODE_150_H
#define LEETCODE_LEETCODE_150_H
#include "allheaders.h"
/** 150. 逆波兰表达式求值
 * */
class Solution {
public:
    int calc(int a, int b, string op) {
        if (op == "*") {
            return a * b;
        }
        if (op == "+") {
            return a + b;
        }
        if (op == "-") {
            return a - b;
        }
        if (op == "/") {
            return a / b;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int ans;
        int l, r;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                r = s.top(); s.pop();
                l = s.top(); s.pop();
                s.push(calc(l, r, tokens[i]));
            }else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
#endif //LEETCODE_LEETCODE_150_H
