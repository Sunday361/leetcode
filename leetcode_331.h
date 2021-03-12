//
// Created by panrenhua on 3/12/21.
//

#ifndef LEETCODE_LEETCODE_331_H
#define LEETCODE_LEETCODE_331_H
#include "allheaders.h"
/** 331. 验证二叉树的前序序列化
 * */
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<string> s;

        stringstream ss(preorder);

        string num;

        while (getline(ss, num, ',')) {
            if (isdigit(num[0])) {
                s.push(num);
            }else {
                while (!s.empty() && s.top() == "#") {
                    s.pop();
                    if (!s.empty() && isdigit(s.top()[0])) {
                        s.pop();
                    }else {
                        return false;
                    }
                }
                s.push("#");
            }
        }

        if (s.size() == 1 && s.top() == "#") return true;
        return false;
    }
};
#endif //LEETCODE_LEETCODE_331_H
