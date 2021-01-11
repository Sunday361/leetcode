//
// Created by panrenhua on 1/11/21.
//

#ifndef LEETCODE_LEETCODE_394_H
#define LEETCODE_LEETCODE_394_H

#include "allheaders.h"
/** 394. 字符串解码
 * */
class Solution {
public:
    string decodeString(string s) {
        string ans;
        int i = 0;
        int letter = 0;
        for (i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int num = 0;
                while(s[i] >= '0' && s[i] <= '9') {
                    num *= 10;
                    num += s[i] - '0';
                    i++;
                }
                letter += 1;
                int j = i;
                while(letter != 0) {
                    j++;
                    if (s[j] == '[') {
                        letter++;
                    }else if (s[j] == ']') {
                        letter--;
                    }
                }
                for (int u = 0; u < num; u++) {
                    ans.append(decodeString(s.substr(i + 1, j - i - 1)));
                }
                i = j;
            }else {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_394_H
