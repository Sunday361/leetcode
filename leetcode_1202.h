//
// Created by panrenhua on 1/11/21.
//

#ifndef LEETCODE_LEETCODE_1202_H
#define LEETCODE_LEETCODE_1202_H

#include "allheaders.h"
/** 1202. 交换字符串中的元素
 *
 * 并查集 路经不压缩过不去 .....
 * */
class Solution {
public:
    vector<int> v;
    int findRoot(int k) {
        /** 并查集 路径压缩 return k == v[k] ? k : (v[k] = findRoot(v[k])); */
        return k == v[k] ? k : (v[k] = findRoot(v[k]));
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        string ans = s;
        for (int i = 0; i < s.size(); i++) {
            v.push_back(i);
        }

        for (int i = 0; i < pairs.size(); i++) {
            int r0 = findRoot(pairs[i][0]);
            int r1 = findRoot(pairs[i][1]);

            if (r0 != r1) {
                v[r0] = r1;
            }
        }

        map<int, vector<int>> m;
        for (int i = 0; i < v.size(); i++) {
            m[findRoot(i)].push_back(i);
        }

        for (auto it = m.begin(); it != m.end(); it++) {
            vector<int> nums(26, 0);

            for (int i = 0; i < it->second.size(); i++) {
                nums[s[it->second[i]] - 'a']++;
            }
            int index = 0;
            for (int i = 0; i < it->second.size(); i++) {
                while(nums[index] == 0) {
                    index++;
                }
                ans[it->second[i]] = index + 'a';
                nums[index]--;
            }
        }

        return ans;
    }
};

#endif //LEETCODE_LEETCODE_1202_H
