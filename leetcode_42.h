//
// Created by panrenhua on 4/2/21.
//

#ifndef LEETCODE_LEETCODE_42_H
#define LEETCODE_LEETCODE_42_H
#include "allheaders.h"
/** 42. 接雨水
 * */
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;

        vector<int> s;

        for (int i = 0; i < height.size(); i++) {
            while (!s.empty() && height[i] > height[s.back()]) {
                int h = height[s.back()];
                s.pop_back();

                if (!s.empty()) {
                    ans += (min(height[s.back()], height[i]) - h) * (i - s.back() - 1);
                }
            }

            s.push_back(i);
        }

        return ans;
    }
};
#endif //LEETCODE_LEETCODE_42_H
