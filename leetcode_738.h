//
// Created by panrenhua on 2020/12/15.
//

#ifndef LEETCODE_LEETCODE_738_H
#define LEETCODE_LEETCODE_738_H

#include "allheaders.h"

/** 738. 单调递增的数字
 * */
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            if (ans.size() == 0) ans.push_back(s[i]);
            else {
                if (s[i] >= ans.back()) {
                    ans.push_back(s[i]);
                }else {
                    int now = s[i];
                    while(ans.size() != 0 && now < ans.back()) {
                        now = ans.back();
                        ans.pop_back();
                        now -= 1;
                    }
                    if (now != '0') ans.push_back(now);
                    while(ans.size() != s.size()) {
                        ans.push_back('9');
                    }
                    if (now == '0') ans.pop_back();
                    return stoi(ans);
                }
            }
        }

        return stoi(ans);
    }
};


#endif //LEETCODE_LEETCODE_738_H
