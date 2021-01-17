//
// Created by panrenhua on 1/17/21.
//

#ifndef LEETCODE_LEETCODE_WEEKLY_CONTEST_224_H
#define LEETCODE_LEETCODE_WEEKLY_CONTEST_224_H

#include "allheaders.h"
/** leetcode-weekly-contest-224
 * */
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<int> ans(rectangles.size(), 0);
        for (int i = 0; i < rectangles.size(); i++) {
            ans[i] = min(rectangles[i][1], rectangles[i][0]);
        }
        int count = 1;
        int p = ans[0];
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i] == p) {
                count++;
            }else if (ans[i] < p){
                continue;
            }else {
                count = 1;
                p = ans[i];
            }
        }
        return count;
    }

    int tupleSameProduct(vector<int>& nums) {
        map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                m[nums[i] * nums[j]]++;
            }
        }
        int ans = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second > 1) {
                int num = it->second;
                ans += (num *(num - 1))/2;
            }
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        sort(heights.begin(), heights.end());
        for (int i = 0; i < heights.size(); i++) {
            ans = (heights[i] * (heights.size() - i) > ans ? heights[i] * (heights.size() - i) : ans);
        }
        return ans;
    }
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> h(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[j][i] == 0) {
                    h[j][i] = 0;
                }else {
                    h[j][i] = (j == 0 ? 1 : h[j - 1][i] + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            ans = max(ans, largestRectangleArea(h[i]));
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_WEEKLY_CONTEST_224_H
