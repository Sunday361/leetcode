//
// Created by panrenhua on 2020/12/16.
//

#ifndef LEETCODE_LEETCODE_290_H
#define LEETCODE_LEETCODE_290_H

#include "allheaders.h"
/** 290. 单词规律
 * */
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        istringstream is = istringstream(s);
        string temp;
        while(getline(is, temp, ' ')) {
            v.push_back(temp);
        }
        unordered_map<string, char> m;
        if (v.size() != pattern.size()) return false;
        for (int i = 0; i < v.size(); i++) {
            if (m.find(v[i]) == m.end()) {
                m[v[i]] = pattern[i];
            }else {
                if (m[v[i]] != pattern[i]) return false;
                continue;
            }
        }
        return true;
    }
};
#endif //LEETCODE_LEETCODE_290_H
