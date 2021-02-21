//
// Created by panrenhua on 1/17/21.
//

#ifndef LEETCODE_LEETCODE_WEEKLY_CONTEST_224_H
#define LEETCODE_LEETCODE_WEEKLY_CONTEST_224_H

#include "allheaders.h"
/** leetcode-weekly-contest-229
 * */
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> left(boxes.size(), 0);
        int l = 0;
        if (boxes[0] == '1') l = 1;
        for (int i = 1; i < boxes.size(); i++) {
            left[i] = left[i - 1] + l;
            if (boxes[i] == '1') l++;
        }
        int r = 0;
        vector<int> right(boxes.size(), 0);
        if (boxes[boxes.size() - 1] == '1') r = 1;
        for (int i = boxes.size() - 2; i >= 0; i--) {
            right[i] = right[i + 1] + r;
            if (boxes[i] == '1') r++;
        }

        vector<int> ans(boxes.size(), 0);

        for (int i = 0; i < ans.size(); i++) {
            ans[i] = left[i] + right[i];
        }
        return ans;
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        int n = nums.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, INT32_MIN));
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++) {
            for (int l = 0; l <= i; l++) {
                int r = i - l;
                int u, v;
                if (l == 0) u = INT32_MIN;
                else u = dp[l - 1][r] + multipliers[l + r - 1] * nums[l - 1];
                if (r == 0) v = INT32_MIN;
                else v = dp[l][r - 1] + multipliers[l + r - 1] * nums[n - r];
                dp[l][r] = max(u, v);
            }
        }
        int ans = INT32_MIN;
        for (int i = 1; i <= m; i++) {
            ans = max(ans, dp[i][m - i]);
        }
        return ans;
    }

    int longestPalindrome(string word1, string word2) {
        string s3 = word1 + word2;
        int l1 = word1.size();
        int l2 = word2.size();
        int n = s3.size();
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int l = 0; l + i - 1 < n; l++) {
                int r = l + i - 1;
                if (i == 1) {
                    dp[l][r] = 1;
                }else {
                    if (s3[l] == s3[r]) {
                        dp[l][r] = dp[l + 1][r - 1] + 2;
                    }else {
                        dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
                    }
                }
                if (l < l1 && r >= l1 && dp[l][r] > ans && s3[l] == s3[r]) {
                    ans = dp[l][r];
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_WEEKLY_CONTEST_224_H
