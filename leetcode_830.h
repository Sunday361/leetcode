//
// Created by panrenhua on 1/5/21.
//

#ifndef LEETCODE_LEETCODE_830_H
#define LEETCODE_LEETCODE_830_H

#include "allheaders.h"
/** 830. 较大分组的位置
 * */
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;

        int begin = 0;

        while(begin < s.size()) {
            int end = begin;

            while(s[end] == s[begin]) {
                end++;
            }

            if (end - begin > 2) {
                ans.push_back({begin, end - 1});
            }
            begin = end;
        }

        return ans;
    }
};
#endif //LEETCODE_LEETCODE_830_H
