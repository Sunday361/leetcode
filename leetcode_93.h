//
// Created by panrenhua on 3/23/21.
//

#ifndef LEETCODE_LEETCODE_93_H
#define LEETCODE_LEETCODE_93_H
#include "allheaders.h"
/** 93. 复原 IP 地址
 * */
class Solution {
public:
    bool check(string& s) {
        if (s.size() > 3) return false;
        if (s[0] == '0' && s.size() != 1) return false;
        else {
            int n = stoi(s);
            if (n > 255) return false;
        }
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int n = s.size();
        for (int i = 0; i <= 2; i++) {
            for (int j = i + 1; j <= i + 3; j++) {
                for (int k = j + 1; k <= j + 3; k++) {
                    if (k + 1 < n) {
                        string s1 = s.substr(0, i + 1);
                        string s2 = s.substr(i + 1, j - i);
                        string s3 = s.substr(j + 1, k - j);
                        string s4 = s.substr(k + 1);

                        if (check(s1) && check(s2) && check(s3) && check(s4)) {
                            ans.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_93_H
