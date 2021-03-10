//
// Created by panrenhua on 3/10/21.
//

#ifndef LEETCODE_LEETCODE_224_H
#define LEETCODE_LEETCODE_224_H
#include "allheaders.h"
/** 224. 基本计算器
 * */
class Solution {
public:
    map<char, int> level;
    string convert(string s) {
        stack<char> ops;
        stringstream ss(s);

        string temp, t;
        while (ss >> temp) {
            if (isdigit(temp[0])) {
                t += temp + " ";
            }else if (temp[0] == '(') {
                ops.push(temp[0]);
            }else if (temp[0] == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    t += string(1, ops.top()) + " ", ops.pop();
                }
                ops.pop();
            }else {
                while (!ops.empty() && level[ops.top()] >= level[temp[0]]) {
                    t += string(1, ops.top()) + " ", ops.pop();
                }
                ops.push(temp[0]);
            }
        }
        while (!ops.empty()) {
            t += string(1, ops.top()) + " ", ops.pop();
        }
        return t;
    }
    int calc(string s) {
        stack<int> nums;
        stringstream ss(s);

        string num;

        while (ss >> num) {
            if (isdigit(num[0])) {
               nums.push(stoi(num));
            }else {
                int r = 0, l = 0, ans;
                if(!nums.empty()) {
                    r = nums.top(); nums.pop();
                }
                if(!nums.empty()) {
                    l = nums.top(); nums.pop();
                }
                if (num == "+") {
                    ans = l + r;
                }else if (num == "-") {
                    ans = l - r;
                }else if (num == "*") {
                    ans = l * r;
                }else {
                    ans = l / r;
                }
                nums.push(ans);
            }
        }
        return nums.top();
    }
    int calculate(string s) {
        string ss = "";
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                if (!ss.empty() && !isdigit(ss.back())) ss.push_back(' ');
                ss.push_back(s[i]);
            }else {
                if (!ss.empty()) ss.push_back(' ');
                ss.push_back(s[i]);
            }
        }
        level['('] = level[')'] = 0;
        level['+'] = level['-'] = 1;
        level['*'] = level['/'] = 2;
        string post = convert(ss);
        return calc(post);
    }
};
#endif //LEETCODE_LEETCODE_224_H
