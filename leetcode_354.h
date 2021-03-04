//
// Created by panrenhua on 3/4/21.
//

#ifndef LEETCODE_LEETCODE_354_H
#define LEETCODE_LEETCODE_354_H

#include "allheaders.h"
/** 354. 俄罗斯套娃信封问题
 * */
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [&](vector<int>& a, vector<int>& b) {
            if (a[0] != b[0]) {return a[0] < a[1];}
            return a[1] > b[1];
        });

        vector<int> dp;
        for (int i = 0; i < envelopes.size(); i++) {
            if (dp.size() == 0) {
                dp.push_back(envelopes[i][1]);
            }else {
                if (envelopes[i][1] > dp.back()) {
                    dp.push_back(envelopes[i][1]);
                }else {
                    auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
                    *it = envelopes[i][1];
                }
            }
        }

        return dp.size();
    }
};

#endif //LEETCODE_LEETCODE_354_H
