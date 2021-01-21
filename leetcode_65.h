//
// Created by panrenhua on 1/21/21.
//

#ifndef LEETCODE_LEETCODE_65_H
#define LEETCODE_LEETCODE_65_H

#include "allheaders.h"
/** 65. 有效数字
 * */
class Solution {
public:
    bool isNumber(string s) {
        string symbol = "";
        string num = "";
        string e = "";
        string exp = "";
        int flag = 0;
        int f = 0, r = s.size() - 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                continue;
            }else {
                f = i;
                break;
            }
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                continue;
            }else {
                r = i;
                break;
            }
        }
        if (r < f) return false;
        if (s[f] == '-' || s[f] == '+') {
            symbol.push_back(s[f++]);
        }
        for (f; f <= r; f++) {
            if (s[f] == 'e' || s[f] == 'E') {
                if (num.size() == 0) return false;
                else {
                    e.push_back(s[f]);
                    f = f + 1;
                    break;
                }
            }else if (s[f] >= '0' && s[f] <= '9'){
                num.push_back(s[f]);
            }else if (s[f] == '.' && flag == 0) {
                num.push_back(s[f]);
                flag = 1;
            }else {
                return false;
            }
        }
        if (s[f] == '-' || s[f] == '+') {
            f++;
        }
        for (int i = f; i <= r; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                exp.push_back(s[i]);
            }else {
                return false;
            }
        }
        if (num.size() == 1 && num.back() == '.') return false;
        if (e.size() != 0 && exp.size() == 0) return false;
        return true;
    }
};
#endif //LEETCODE_LEETCODE_65_H
