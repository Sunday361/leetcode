//
// Created by panrenhua on 2020/12/13.
//

#ifndef LEETCODE_LEETCODE_WEEKLY_CONTEST_219_H
#define LEETCODE_LEETCODE_WEEKLY_CONTEST_219_H
#include "allheaders.h"

/** 219. 周赛
 * */
class Solution {
public:
    /** 5625. 比赛中的配对次数
    * */
    int numberOfMatches(int n) {
        if (n == 1) return 0;
        if (n == 0) return 0;
        if (n % 2 == 0) return n/2 + numberOfMatches(n/2);
        else if (n % 2 == 1) return n/2 + numberOfMatches(n/2 + 1);
    }

    /** 5626. 十-二进制数的最少数目
     * */
    int minPartitions(string n) {
        int ans = 1;
        int pre = 1;
        for (int i = 0; i < n.size(); i++) {
            while(n[i] - '0' - pre > 0) {
                pre++;
                ans++;
            }
            if (pre == 9) {
                break;
            }
        }
        return ans;
    }
    /** 5627. 石子游戏 VII
     * */
    int stoneGameVII(vector<int>& stones) {
        vector<int> sum(stones.size() + 1, 0);
        for (int i = 1; i <= stones.size(); i++) {
            sum[i] = sum[i - 1] + stones[i - 1];
        }
        vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), 0));

        if (stones.size() % 2 == 0) {
            for (int i = 2; i <= stones.size(); i++) {
                for (int j = 0; j <= stones.size() - i; j++) {
                    if (i % 2 == 0) {
                        dp[j][j + i - 1] = max(dp[j + 1][j + i - 1] + sum[j + i] - sum[j + 1], dp[j][j + i - 2] + sum[j + i - 1] - sum[j]);
                    }else {
                        dp[j][j + i - 1] = min(dp[j + 1][j + i - 1] - (sum[j + i] - sum[j + 1]), dp[j][j + i - 2] - (sum[j + i - 1] - sum[j]));
                    }
                }
            }
        } else {
            for (int i = 2; i <= stones.size(); i++) {
                for (int j = 0; j <= stones.size() - i; j++) {
                    if (i % 2 == 1) {
                        dp[j][j + i - 1] = max(dp[j + 1][j + i - 1] + sum[j + i] - sum[j + 1], dp[j][j + i - 2] + sum[j + i - 1] - sum[j]);
                    }else {
                        dp[j][j + i - 1] = min(dp[j + 1][j + i - 1] - (sum[j + i] - sum[j + 1]), dp[j][j + i - 2] - (sum[j + i - 1] - sum[j]));
                    }
                }
            }
        }
        return dp[0][stones.size() - 1];
    }
    /** 5245. 堆叠长方体的最大高度
     * 考虑 a1>=b1>=c1 和 a2>=b2>=c2
     * 若 两者可以满足题设条件 则有 以 a,b 为底 以 c 为高 为最优解
     * 所以考虑以 cuboids[i] 为底 将前面的 长方体累加上去 即可得到当前的最优解
    * */
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for (auto &c : cuboids)
            sort(c.begin(), c.end());
        sort(cuboids.begin(), cuboids.end());
        vector<int> dp(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j)
                if (cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2])
                    dp[i] = max(dp[i], dp[j]);
            dp[i] += cuboids[i][2];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};



#endif //LEETCODE_LEETCODE_WEEKLY_CONTEST_219_H
