//
// Created by panrenhua on 2020/12/14.
//

#ifndef LEETCODE_LEETCODE_49_H
#define LEETCODE_LEETCODE_49_H

#include "allheaders.h"
/** 49. 字母异位词分组
 *
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string, int> m;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if (m.find(temp) == m.end()) {
                m[temp] = ans.size();
                ans.push_back({});
                ans.back().push_back(strs[i]);
            }else {
                ans[m[temp]].push_back(strs[i]);
            }
        }
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_49_H
