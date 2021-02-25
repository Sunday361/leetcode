//
// Created by panrenhua on 2/25/21.
//

#ifndef LEETCODE_LEETCODE_8_H
#define LEETCODE_LEETCODE_8_H

#include "allheaders.h"
/** 8. 字符串转换整数 (atoi)
 * */
class Solution {
public:
    int myAtoi(string s) {
        long num = 0, symbol = 1;
        int fn = 0, fs = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] <= '9' && s[i] >= '0') {
                num *= 10;
                num += s[i] - '0';
                if (symbol * num > INT32_MAX){
                    return INT32_MAX;
                }else if (symbol * num < INT32_MIN) {
                    return INT32_MIN;
                }
                fn = 1;
            }else if ((s[i] == '-' || s[i] == '+') && fn != 1 && fs != 1) {
                symbol = s[i] == '-' ? -1 : 1;
                fs = 1;
            }else if (s[i] == ' ' && fn != 1 && fs != 1) {
                continue;
            }else {
                break;
            }
        }
        return symbol * num;
    }
};
#endif //LEETCODE_LEETCODE_8_H
